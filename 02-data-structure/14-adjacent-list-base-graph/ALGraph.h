#pragma once
#include <iostream>
#include "../03-double-linked-list/DoubleLinkedList.h"
using namespace dllist;

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

    private:
        int numOfVertex;
        int numOfEdge;
        DLList<T>* adjacentList;
    };

    template<typename T>
    ALGraph<T>::ALGraph(int numOfVertex) : numOfVertex(numOfVertex), numOfEdge(0)
    {
        int i;
        adjacentList = new DLList<T>[numOfVertex];

        for(i = 0; i < numOfVertex; ++i)
            adjacentList[i] = DLList<T>();
    }

    template<typename T>
    ALGraph<T>::~ALGraph()
    {
        if(adjacentList != nullptr)
            delete[] adjacentList;
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
}
