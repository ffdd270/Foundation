#include "ALGraph.h"

using namespace algraph;

int main()
{

    ALGraph<VERTEX> graph(5);

    graph.AddEdge(VERTEX::A, VERTEX::B);
    graph.AddEdge(VERTEX::A, VERTEX::D);
    graph.AddEdge(VERTEX::B, VERTEX::C);
    graph.AddEdge(VERTEX::C, VERTEX::D);
    graph.AddEdge(VERTEX::D, VERTEX::E);
    graph.AddEdge(VERTEX::E, VERTEX::A);

    graph.ShowGraphEdgeInfo();

    return 0;
}