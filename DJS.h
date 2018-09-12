#ifndef KRUSKAL_DJS_H
#define KRUSKAL_DJS_H

class DJS {
    int *p, *rank;
public:
    ~DJS();
    explicit DJS(unsigned long);
    bool Union(int, int);
    int Find(int);
};

#endif
