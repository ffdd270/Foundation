#include <iostream>
#include "ALGraphDFS.h"

using namespace algraph;

int main()
{
    ALGraph<VERTEX> graph(7);

    graph.AddEdge(VERTEX::A, VERTEX::B);
    graph.AddEdge(VERTEX::A, VERTEX::D);
    graph.AddEdge(VERTEX::B, VERTEX::C);
    graph.AddEdge(VERTEX::D, VERTEX::C);
    graph.AddEdge(VERTEX::D, VERTEX::E);
    graph.AddEdge(VERTEX::E, VERTEX::F);
    graph.AddEdge(VERTEX::E, VERTEX::G);

    graph.ShowGraphEdgeInfo();

    graph.DFShowGraphVertex(VERTEX::A); std::cout << std::endl;
    graph.DFShowGraphVertex(VERTEX::C); std::cout << std::endl;
    graph.DFShowGraphVertex(VERTEX::E); std::cout << std::endl;
    graph.DFShowGraphVertex(VERTEX::G); std::cout << std::endl;
    
    return 0;
}