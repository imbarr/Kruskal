#include "catch.hpp"
#include "kruskal.h"
#include "point.h"
#include "util.h"

const size_t points = 5;
const int tries = 1;

TEST_CASE("Correct results on random data", "[vector]") {
    for(int count = 0; count < tries; count++) {
        Point coords[points];
        auto edges = std::vector<Edge>(points*(points - 1)/2);
        for(int i = 0; i < points; i++) {
            coords[i] = Point(std::rand(), std::rand());
            for(int j = 0; j < i; j++)
                edges.emplace_back(Edge(j, i, rectangleMetric(coords[j], coords[i])));
        }
        std::sort(edges.begin(), edges.end());
        double size = kruskal(points, edges).second;
        while(std::next_permutation(edges.begin(), edges.end())) {
            auto pair = kruskal(points, edges);
            CHECK(kruskal(points, edges).second >= size);
            for(int i = 0; i < points; i++)
                delete pair.first[i];
            delete[] pair.first;
        }
    }
}