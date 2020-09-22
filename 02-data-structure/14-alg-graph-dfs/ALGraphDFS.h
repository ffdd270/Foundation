#pragma once
#include <iostream>
#include "../03-double-linked-list/DoubleLinkedList.h"
using namespace dllist;
#include "../06-list-base-stack/ListBaseStack.h"
using namespace liststack;

namespace algraph
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

        void AddEdge(T fromVertex, T toVertex);
        void ShowGraphEdgeInfo();
        void DFShowGraphVertex(T startVertex);

        bool VisitVertex(T visitVertex);

    private:
        int numOfVertex;
        int numOfEdge;
        DLList<T>* adjacentList;
        bool* visitInfo;
    };

    template<typename T>
    ALGraph<T>::ALGraph(int numOfVertex) : numOfVertex(numOfVertex), numOfEdge(0)
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
    void ALGraph<T>::AddEdge(T fromVertex, T toVertex)
    {
        adjacentList[static_cast<int>(fromVertex)].Insert(toVertex);
        adjacentList[static_cast<int>(toVertex)].Insert(fromVertex);
        numOfEdge++;
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
    bool ALGraph<T>::VisitVertex(T visitVertex)
    {
        if(!visitInfo[static_cast<int>(visitVertex)])
        {
            visitInfo[static_cast<int>(visitVertex)] = true;
            return true;
        }

        return false;
    }
}
