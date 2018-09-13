#ifndef KRUSKAL_EDGE_H
#define KRUSKAL_EDGE_H

struct Edge {
    Edge() = default;
    Edge(int, int, double);
    int first;
    int second;
    double weight;
    bool operator<(Edge);
};

#endif
