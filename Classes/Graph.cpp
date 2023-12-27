//
// Created by pedrosspedro on 22-12-2023.
//

#include "Graph.h"

//Graph functions

bool Graph::addVertex(Airport *in) {
    if ( findVertex(in->getCode()) != nullptr)
        return false;
    vertexSet.push_back(new Vertex(in));
    return true;
}

bool Graph::addEdge(const string& sourcCode, const string& destCode, const string& airline) {
    auto v1 = findVertex(sourcCode);
    auto v2 = findVertex(destCode);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2,airline);
    return true;
}

Vertex *Graph::findVertex(const string& in) const {
    for (auto v : vertexSet)
        if (v->airport->getCode() == in)
            return v;
    return nullptr;
}

//Vertex functions

Vertex::Vertex(Airport* in) {
    airport = in;
}

Airport* Vertex::getAirport() const {
    return airport;
}

void Vertex::setAirport(Airport* in) {
    airport = in;
}

void Vertex::addEdge(Vertex *dest, string airline) {
    adj.push_back(Edge(dest, airline));
}

//Edge functions

Edge::Edge(Vertex *d, string airline) {
    this->dest = d;
    this->airline = airline;
}
