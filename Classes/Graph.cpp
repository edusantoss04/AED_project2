//
// Created by pedrosspedro on 22-12-2023.
//

#include "Graph.h"

bool Graph::addVertex(const Airport &in) {
    if ( findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}

bool Graph::addEdge(const Airport &sourc, const Airport &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2,w);
    return true;
}

Vertex *Graph::findVertex(const Airport &in) const {
    for (auto v : vertexSet)
        if (v->airport == in)
            return v;
    return nullptr;
}
