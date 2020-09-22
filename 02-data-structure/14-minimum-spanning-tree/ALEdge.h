#pragma once

namespace kruskal
{
    template <typename T>
    struct Edge
    {
        T vertex1;
        T vertex2;
        int weight;
    };
}