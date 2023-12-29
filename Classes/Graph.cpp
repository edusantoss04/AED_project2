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

/*
vector<Airport> Graph::dfs(Airport &airport) const {

    vector<Airport> airports;
    auto vertex = findVertex(airport.getCode());

    for(auto vertex: vertexSet){
        vertex.second->visited = false;
    }

    dfsVisit(vertex, airports);
    return airports;
}

void Graph::dfsVisit(Vertex *v, vector<Airport> &res) const {

    v->visited = true;
    res.push_back(*v->getAirport());

    for (Edge edj: v->getAdj()){
        auto w = edj.getDest();
        if (!w->visited){
            dfsVisit(w, res);
        }
    }
}*/

vector<int> Graph::bfs(const string& airportCode)const {
    unordered_set<string> airports;
    unordered_set<string> cities;
    unordered_set<string> countries;

    auto vertex= findVertex(airportCode);

    if(vertex== nullptr){
        return {0,0,0};
    }
    queue<Vertex*> queue1;
    for(auto v:vertexSet){
        v.second->setVisited(false);
    }

    queue1.push(vertex);
    vertex->setVisited(false);

    while(!queue1.empty()){
        auto vertex1= queue1.front();
        queue1.pop();
        for(auto& edg:vertex1->getAdj()){
            auto w= edg.getDest();
            if(!w->isVisited()){
                airports.insert(w->getAirport()->getCode());
                cities.insert(w->getAirport()->getCity());
                countries.insert(w->getAirport()->getCountry());
                queue1.push(w);
                w->setVisited(true);
            }
        }
    }
    int airportsSize=airports.size();
    int countriesSize=countries.size();
    int citiesSize=cities.size();

    return {airportsSize,countriesSize,citiesSize};
}

vector<int> Graph::bfsStops(const string &airportCode, int k) const {
    unordered_set<string> airports;
    unordered_set<string> cities;
    unordered_set<string> countries;

    auto vertex= findVertex(airportCode);

    if(vertex== nullptr){
        return {0,0,0};
    }
    queue<Vertex*> queue1;
    for(auto v:vertexSet){
        v.second->setVisited(false);
    }

    queue1.push(vertex);
    vertex->setVisited(false);

    while(k >= 0) {

        int size = queue1.size();

        while (size > 0) {
            auto vertex1 = queue1.front();
            queue1.pop();

            for (auto &edg: vertex1->getAdj()) {
                auto w = edg.getDest();
                if (!w->isVisited()) {
                    airports.insert(w->getAirport()->getCode());
                    cities.insert(w->getAirport()->getCity());
                    countries.insert(w->getAirport()->getCountry());
                    queue1.push(w);
                    w->setVisited(true);
                }
            }
            size--;
        }
        k--;
    }
    int airportsSize=airports.size();
    int countriesSize=countries.size();
    int citiesSize=cities.size();

    return {airportsSize,countriesSize,citiesSize};
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
