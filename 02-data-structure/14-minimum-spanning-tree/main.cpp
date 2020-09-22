#include <iostream>
#include "ALGraphKruskal.h"
using namespace kruskal;

int main()
{
    ALGraph<VERTEX> graph(6);

    graph.AddEdge(VERTEX::A, VERTEX::B, 9);
    graph.AddEdge(VERTEX::B, VERTEX::C, 2);
    graph.AddEdge(VERTEX::A, VERTEX::C, 12);
    graph.AddEdge(VERTEX::A, VERTEX::D, 8);
    graph.AddEdge(VERTEX::D, VERTEX::C, 6);
    graph.AddEdge(VERTEX::A, VERTEX::F, 11);
    graph.AddEdge(VERTEX::F, VERTEX::D, 4);
    graph.AddEdge(VERTEX::D, VERTEX::E, 3);
    graph.AddEdge(VERTEX::E, VERTEX::C, 7);
    graph.AddEdge(VERTEX::F, VERTEX::E, 13);

    graph.ConstituteKruskalMST();
    graph.ShowGraphEdgeInfo();
    graph.ShowGraphEdgeWeightInfo();
    return 0;
}