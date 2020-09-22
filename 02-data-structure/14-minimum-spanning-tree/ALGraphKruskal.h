#pragma once
#include <iostream>
#include "../03-double-linked-list/DoubleLinkedList.h"
using namespace dllist;
#include "../06-list-base-stack/ListBaseStack.h"
using namespace liststack;
#include "../09-priority-queue/PriorityQueue.h"
using namespace priorityqueue;
#include "ALEdge.h"

namespace kruskal
{
    enum class VERTEX
    {
        A, B, C, D, E, F, G, H, I, J
    };

    template <typename T>
    struct ALGraph
    {
    public:
        explicit ALGraph(int numOfVertex);
        ~ALGraph();

        void AddEdge(T fromVertex, T toVertex, int weight);
        void ShowGraphEdgeInfo();
        void DFShowGraphVertex(T startVertex);

        void ConstituteKruskalMST();
        void ShowGraphEdgeWeightInfo();

        bool VisitVertex(T visitVertex);

    private:
        int numOfVertex;
        int numOfEdge;
        DLList<T>* adjacentList;
        bool* visitInfo;
        PriorityQueue<Edge<T>> priorityQueue;

        void RemoveEdge(T fromVertex, T toVertex);
        void RemoveWayEdge(T fromVertex, T toVertex);
        void RecoverEdge(T fromVertex, T toVertex, int weight);
        bool IsConnectedVertex(T v1, T v2);
    };

    template <typename T>
    int PQWeightComp(Edge<T> d1, Edge<T> d2)
    {
        return d1.weight - d2.weight;
    }

    template<typename T>
    ALGraph<T>::ALGraph(int numOfVertex) : numOfVertex(numOfVertex), numOfEdge(0), priorityQueue(PQWeightComp)
    {
        int i;
        adjacentList = new DLList<T>[numOfVertex];
        visitInfo = new bool[numOfVertex];

        for(i = 0; i < numOfVertex; ++i)
            adjacentList[i] = DLList<T>();

        memset(visitInfo, false, sizeof(bool) * numOfVertex);
    }

    template<typename T>
    ALGraph<T>::~ALGraph()
    {
        delete[] adjacentList;
        delete[] visitInfo;
    }

    template<typename T>
    void ALGraph<T>::AddEdge(T fromVertex, T toVertex, int weight)
    {
        Edge<T> edge = {fromVertex, toVertex, weight};

        adjacentList[static_cast<int>(fromVertex)].Insert(toVertex);
        adjacentList[static_cast<int>(toVertex)].Insert(fromVertex);
        numOfEdge += 1;

        priorityQueue.Enqueue(edge);
    }

    template<typename T>
    void ALGraph<T>::ShowGraphEdgeInfo()
    {
        int i;
        T vertex;

        for(i = 0; i < numOfVertex; ++i)
        {
            std::cout << char(i + 65) << " with ";

            if(adjacentList[i].First(&vertex))
            {
                std::cout << char(static_cast<int>(vertex) + 65) << " ";

                while(adjacentList[i].Next(&vertex))
                    std::cout << char(static_cast<int>(vertex) + 65) << " ";
            }
            std::cout << std::endl;
        }
    }

    template<typename T>
    void ALGraph<T>::DFShowGraphVertex(T startVertex)
    {
        ListStack<T> stack;
        T visitVertex = startVertex;
        T nextVertex;

        VisitVertex(visitVertex);
        stack.Push(visitVertex);

        while(adjacentList[static_cast<int>(visitVertex)].First(&nextVertex))
        {
            bool visitFlag = false;

            if(VisitVertex(nextVertex))
            {
                stack.Push(visitVertex);
                visitVertex = nextVertex;
                visitFlag = true;
            }
            else
            {
                while(adjacentList[static_cast<int>(visitVertex)].Next(&nextVertex))
                {
                    if(VisitVertex(nextVertex))
                    {
                        stack.Push(visitVertex);
                        visitVertex = nextVertex;
                        visitFlag = true;
                        break;
                    }
                }
            }

            if(!visitFlag)
            {
                if(stack.IsEmpty())
                    break;
                else
                    visitVertex = stack.Pop();
            }
        }

        memset(visitInfo, false, sizeof(bool) * numOfVertex);
    }

    template<typename T>
    void ALGraph<T>::ConstituteKruskalMST()
    {
        Edge<T> recoverEdge[20];
        Edge<T> edge;
        int edgeIndex = 0;
        int i;

        while(numOfEdge + 1 > numOfVertex)
        {
            edge = priorityQueue.Dequeue();
            RemoveEdge(edge.vertex1, edge.vertex2);

            if(!IsConnectedVertex(edge.vertex1, edge.vertex2))
            {
                RecoverEdge(edge.vertex1, edge.vertex2, edge.weight);
                recoverEdge[edgeIndex++] = edge;
            }
        }

        for(i = 0; i < edgeIndex; ++i)
            priorityQueue.Enqueue(recoverEdge[i]);
    }

    template<typename T>
    void ALGraph<T>::ShowGraphEdgeWeightInfo()
    {
        PriorityQueue<Edge<T>> priorityQueueCopy = priorityQueue;
        Edge<T> edge;

        while(!priorityQueueCopy.IsEmpty())
        {
            edge = priorityQueueCopy.Dequeue();
            std::cout << "(" << char(static_cast<int>(edge.vertex1) + 65) << "-"
                             << char(static_cast<int>(edge.vertex2) + 65)
                             << "), Weight : " << edge.weight << std::endl;
        }
    }

    template<typename T>
    bool ALGraph<T>::VisitVertex(T visitVertex)
    {
        if(!visitInfo[static_cast<int>(visitVertex)])
        {
            visitInfo[static_cast<int>(visitVertex)] = true;
            return true;
        }

        return false;
    }

    template<typename T>
    void ALGraph<T>::RemoveEdge(T fromVertex, T toVertex)
    {
        RemoveWayEdge(fromVertex, toVertex);
        RemoveWayEdge(toVertex, fromVertex);
        numOfEdge--;
    }

    template<typename T>
    void ALGraph<T>::RemoveWayEdge(T fromVertex, T toVertex)
    {
        T edge;

        if(adjacentList[static_cast<int>(fromVertex)].First(&edge))
        {
            if(edge == toVertex)
            {
                adjacentList[static_cast<int>(fromVertex)].Remove();
                return;
            }

            while(adjacentList[static_cast<int>(fromVertex)].Next(&edge))
            {
                if(edge == toVertex)
                {
                    adjacentList[static_cast<int>(fromVertex)].Remove();
                    return;
                }
            }
        }
    }

    template<typename T>
    void ALGraph<T>::RecoverEdge(T fromVertex, T toVertex, int weight)
    {
        adjacentList[static_cast<int>(fromVertex)].Insert(toVertex);
        adjacentList[static_cast<int>(toVertex)].Insert(fromVertex);
        numOfEdge++;
    }

    template<typename T>
    bool ALGraph<T>::IsConnectedVertex(T v1, T v2)
    {
        ListStack<T> stack;
        T visitVertex = v1;
        T nextVertex;

        VisitVertex(visitVertex);
        stack.Push(visitVertex);

        while(adjacentList[static_cast<int>(visitVertex)].First(&nextVertex))
        {
            bool visitFlag = false;

            if(nextVertex == v2)
            {
                memset(visitInfo, false, sizeof(bool) * numOfVertex);
                return true;
            }

            if(VisitVertex(nextVertex))
            {
                stack.Push(visitVertex);
                visitVertex = nextVertex;
                visitFlag = true;
            }
            else
            {
                while(adjacentList[static_cast<int>(visitVertex)].Next(&nextVertex))
                {
                    if(nextVertex == v2)
                    {
                        memset(visitInfo, false, sizeof(bool) * numOfVertex);
                        return true;
                    }

                    if(VisitVertex(nextVertex))
                    {
                        stack.Push(visitVertex);
                        visitVertex = nextVertex;
                        visitFlag = true;
                        break;
                    }
                }
            }

            if(!visitFlag)
            {
                if(stack.IsEmpty())
                    break;
                else
                    visitVertex = stack.Pop();
            }
        }

        memset(visitInfo, false, sizeof(bool) * numOfVertex);
        return false;
    }
}