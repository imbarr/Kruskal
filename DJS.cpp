#include "DJS.h"

DJS::DJS(unsigned long number) {
    p = new int[number];
    rank = new int[number];
    for(int i = 0; i < number; i++) {
        p[i] = i;
        rank[i] = 0;
    }
}

DJS::~DJS() {
    delete[] p;
    delete[] rank;
}

int DJS::Find(int elem) {
    return p[elem] == elem ? elem : p[elem] = Find(p[elem]);
}

bool DJS::Union(int elem1, int elem2) {
    if((elem1 = Find(elem1)) == (elem2 = Find(elem2)))
        return false;

    if(rank[elem1] > rank[elem2])
        p[elem2] = elem1;
    else {
        p[elem1] = elem2;
        if(rank[elem1] == rank[elem2])
            rank[elem2]++;
    }
    return true;
}