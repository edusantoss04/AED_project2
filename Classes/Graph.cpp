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

unordered_map<string, Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

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

bool isIn(stack<string> s, string airportCode);
void Graph::dfsArt(Vertex* vertex, stack<string>& s, unordered_set<string>& set, int& x, string rootNode){

    vertex->setVisited(true);
    vertex->setLow(x);
    vertex->setNum(x);
    x++;
    s.push(vertex->getAirport()->getCode());
    int child = 0;

    for (auto edg: vertex->getAdj()){

        auto w = edg.getDest();

        if (!w->isVisited()){
            child++;
            dfsArt(w, s, set, x, rootNode);
            vertex->setLow(min(vertex->getLow(), w->getLow()));

            if (w->getLow() >= vertex->getNum()){
                set.insert(vertex->getAirport()->getCode());
            }
        }
        else if (isIn(s, w->getAirport()->getCode())){

            vertex->setLow(min(vertex->getLow(), w->getNum()));
        }
    }

    if (vertex->getAirport()->getCode() == rootNode){
        if (child <= 1){
            set.erase(vertex->getAirport()->getCode());
        }
    }
    s.pop();
}

void Graph::findAllPaths(const string& current, const string& dest, vector<string>& currentPath, vector<vector<string>>& allPaths) {
    currentPath.push_back(current);

    if (current == dest) {
        allPaths.push_back(currentPath);
    } else {
        for (const auto& parent : vertexSet.at(current)->parent) {
            findAllPaths(parent, dest, currentPath, allPaths);
        }
    }

    currentPath.pop_back();
}

vector<vector<string>> Graph::getPath(const string& origin, const string& dest,vector<string>& airlines) {
    vector<vector<string>> allPaths;
    allPaths.clear();

    if (airlines.size() == 0) {
        bfsPath(origin);
    } else {
        bfsWithFilters(origin, airlines);
    }

    vector<string> currentPath;
    currentPath.clear();
    findAllPaths(dest, origin, currentPath, allPaths);


    for (auto& path : allPaths) {
        reverse(path.begin(), path.end());

    }
    auto last = unique(allPaths.begin(), allPaths.end());
    allPaths.erase(last, allPaths.end());
    cout<<"These are the best ways to travel from " <<origin << " to " << dest <<" :" <<endl ;
    for(auto i: allPaths){

        for(auto x: i){
            if(x==dest){
                cout<< dest;
                break;
            }
            cout<< x <<" -> ";

        }
        cout << endl;
    }

    return allPaths;
}

void Graph::bfsPath(const string &airportCode) {

    for (auto v: vertexSet){
        v.second->setVisited(false);
        v.second->setDistance(-1);
    }

    queue<string> q; // queue of unvisited nodes
    q.push(airportCode);
    vertexSet[airportCode]->setVisited(true);
    vertexSet[airportCode]->setDistance(0);

    while (!q.empty()) { // while there are still unvisited nodes

        string u = q.front();
        q.pop();

        auto vertex = vertexSet[u];

        for (const auto& e : vertex->adj) {
            string airportD = e.getDest()->getAirport()->getCode();

            if (!vertexSet[airportD]->visited) {
                q.push(airportD);
                vertexSet[airportD]->visited = true;
                vertexSet[airportD]->parent.push_back(u);
                vertexSet[airportD]->distance = vertexSet[u]->distance+1;
            }
            else if (vertexSet[airportD]->distance == vertexSet[u]->distance + 1 &&
                     find(vertexSet[airportD]->parent.begin(), vertexSet[airportD]->parent.end(), u) ==
                     vertexSet[airportD]->parent.end()) {
                vertexSet[airportD]->parent.push_back(u);
            }
        }
    }
}

void Graph::bfsWithFilters(const string &airportCode, vector<string> &airlines) {

    for (auto v: vertexSet) {
        v.second->setVisited(false);
        v.second->setDistance(-1);
    }

    queue<string> q; // queue of unvisited nodes
    q.push(airportCode);
    vertexSet[airportCode]->setVisited(true);
    vertexSet[airportCode]->setDistance(0);

    while (!q.empty()) { // while there are still unvisited nodes

        string u = q.front();
        q.pop();

        auto node = vertexSet[u];

        for (const auto &e: node->getAdj()) {
            if (find(airlines.begin(), airlines.end(), e.airline) != airlines.end()) {
                string airportD = e.dest->getAirport()->getCode();

                if (!vertexSet[airportD]->visited) {
                    q.push(airportD);
                    vertexSet[airportD]->visited = true;
                    vertexSet[airportD]->parent.push_back(u);
                    vertexSet[airportD]->distance = vertexSet[u]->distance + 1;
                } else if (vertexSet[airportD]->distance == vertexSet[u]->distance + 1) {
                    vertexSet[airportD]->parent.push_back(u);
                }
            }

        }
    }
}

/**
* @brief Checks if a given airport code is present in the given stack.
*
* This function iterates through the elements of the stack to determine if a specified airport code is present.
*
* @param s The stack to search for the airport code.
* @param airportCode The airport code to check for.
* @return True if the airport code is present in the stack, false otherwise.
*/
bool isIn(stack<string> s, string airportCode){

    while (!s.empty()){
        if (airportCode == s.top()){
            return true;
        }
        s.pop();
    }
    return false;
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

int Vertex::getOutdegree() const {
    return outdegree;
}

void Vertex::setOutdegree(int outdegree) {
    this->outdegree=outdegree;
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

int Vertex::getdistance() {
    return distance;
}

void Vertex::setDistance(int distance) {
    this->distance = distance;
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
