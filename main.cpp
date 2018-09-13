#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "edge.h"
#include "kruskal.h"
#include "util.h"

void task(std::ifstream &input, std::ofstream &output) {
    unsigned int n;
    input >> n;
    auto graph = fromInput(n, input, rectangleMetric);
    std::sort(graph.begin(), graph.end());
    auto pair = kruskal(n, graph);
    auto list = pair.first;
    for(int i = 0; i < n; i++) {
        for(auto e : *list[i])
            output << e + 1 << ' ';
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