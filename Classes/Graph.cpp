//
// Created by pedrosspedro on 22-12-2023.
//

#include "Graph.h"

//Graph functions

bool Graph::addVertex(Airport *in) {
    if ( findVertex(in->getCode()) != nullptr)
        return false;
    vertexSet.insert({in->getCode(), new Vertex(in)});
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

Vertex *Graph::findVertex(const string& airportCode) const {

    auto it = vertexSet.find(airportCode);

    if (it != vertexSet.end()){
        return it->second;
    }

    return nullptr;
}

int Graph::getNumVertex() const {
    return vertexSet.size();
}

unordered_map<string, Vertex *> Graph::getVertexSet() const {
    return vertexSet;
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

bool Vertex::isVisited() const {
    return visited;
}

void Vertex::setVisited(bool v) {
    visited = v;
}

bool Vertex::isProcessing() const {
    return processing;
}

void Vertex::setProcessing(bool p) {
    processing = p;
}

const vector<Edge> &Vertex::getAdj() const {
    return adj;
}

int Vertex::getIndegree() const {
    return indegree;
}

void Vertex::setIndegree(int indegree) {
    this->indegree = indegree;
}

int Vertex::getNum() const {
    return num;
}

void Vertex::setNum(int num) {
    this->num = num;
}

int Vertex::getLow() const {
    return low;
}

void Vertex::setLow(int low) {
    this->low = low;
}

//Edge functions

Edge::Edge(Vertex *d, string airline) {
    this->dest = d;
    this->airline = airline;
}

Vertex *Edge::getDest() const {
    return dest;
}

string Edge::getAirline() const {
    return airline;
}
