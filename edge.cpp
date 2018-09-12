#include "edge.h"

Edge::Edge(int first, int second, double weight) {
    this->first = first;
    this->second = second;
    this->weight = weight;
}

bool Edge::operator<(Edge other) {
    return weight < other.weight;
}