#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "edge.h"
#include "kruskal.h"

using coord = std::pair<double, double>;

std::vector<Edge> fromInput(int n, std::ifstream &input, double (*metric)(coord, coord)) {
    auto coords = new coord[n];
    auto result = std::vector<Edge>();
    for(int i = 0; i < n; i++) {
        double x, y;
        input >> x >> y;
        coords[i] = coord(x, y);
        for(int j = 0; j < i; j++)
            result.emplace_back(Edge(j, i, metric(coords[j], coords[i])));
    }
    delete[] coords;
    return result;
}

double rectangleMetric(coord a, coord b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

void task(std::ifstream &input, std::ofstream &output) {
    unsigned int n;
    input >> n;
    auto graph = fromInput(n, input, rectangleMetric);
    auto pair = kruskal(n, graph);
    auto list = pair.first;
    for(int i = 0; i < n; i++) {
        for(auto e : *list[i])
            output << e << ' ';
        output << 0 << '\n';
        delete list[i];
    }
    output << pair.second;
    delete[] list;
}

int main() {
    std::ifstream input(".\\input.txt");
    std::ofstream output(".\\output.txt");
    task(input, output);
    input.close();
    output.close();
}