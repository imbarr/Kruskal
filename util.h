#ifndef KRUSKAL_UTIL_H
#define KRUSKAL_UTIL_H

#include <utility>
#include <fstream>
#include <vector>
#include "edge.h"
#include "point.h"

std::vector<Edge> fromInput(unsigned int n, std::ifstream &input, double (*)(Point, Point));

double rectangleMetric(Point a, Point b);

#endif
