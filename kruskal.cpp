#include <algorithm>
#include "kruskal.h"
#include "DJS.h"

std::pair<std::vector<int>**, double> kruskal(unsigned int n, std::vector<Edge> sortedEdges) {
    auto result = new std::vector<int>*[n];
    for(int i = 0; i < n; i++)
        result[i] = new std::vector<int>();
    auto djs = DJS(n);
    double weight = 0;
    for(Edge e : sortedEdges)
        if(djs.Union(e.first, e.second)) {
            result[e.first]->push_back(e.second);
            result[e.second]->push_back(e.first);
            weight += e.weight;
        }
    return std::pair(result, weight);
}
