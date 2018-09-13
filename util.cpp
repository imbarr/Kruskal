#include "util.h"

std::vector<Edge> fromInput(unsigned int n, std::ifstream &input, double (*metric)(Point, Point)) {
    auto coords = new Point[n];
    auto result = std::vector<Edge>();
    for(int i = 0; i < n; i++) {
        double x, y;
        input >> x >> y;
        coords[i] = Point(x, y);
        for(int j = 0; j < i; j++)
            result.emplace_back(Edge(j, i, metric(coords[j], coords[i])));
    }
    delete[] coords;
    return result;
}

double rectangleMetric(Point a, Point b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}