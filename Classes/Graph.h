#ifndef AED_PROJECT2_GRAPH_H
#define AED_PROJECT2_GRAPH_H

#include <cstddef>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include "Airport.h"

using namespace std;

class Edge;
class Graph;
class Vertex;

class Vertex {
    Airport* airport;
    vector<Edge> adj;
    string parent;
    bool visited;
    bool processing;
    int indegree;
    int outdegree;
    int num;
    int distance;
    int low;

    void addEdge(Vertex *dest, string airline);

public:
    Vertex(Airport* in);
    Airport* getAirport() const;
    void setAirport(Airport* in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge> &getAdj() const;

    int getIndegree() const;
    void setIndegree(int indegree);

    int getOutdegree() const;
    void setOutdegree(int outdegree);

    int getNum() const;
    void setNum(int num);

    int getLow() const;
    void setLow(int low);

    int getdistance();
    void setDistance(int distance);

    friend class Graph;
};

class Edge {
    Vertex * dest;      // destination vertex
    string airline ;         // edge weight
public:
    Edge(Vertex *d, string airline);
    Vertex *getDest() const;
    string getAirline() const;

    friend class Graph ;
    friend class Vertex ;
};


class Graph {
    unordered_map<string, Vertex*> vertexSet;

public:
    Vertex *findVertex(const string& airportCode) const;
    bool addVertex(Airport *in);
    bool addEdge(const string& sourcCode, const string& destCode, const string& airline);
    unordered_map<string, Vertex*> getVertexSet() const;

    vector<int> bfs(const string& airportCode)const;
    vector<int> bfsStops(const string& airportCode, int k)const;
    void bfsPath(const string& airportCode);
    void bfsWithFilters(const string& airportCode, vector<string>& airlines);
    void dfsArt(Vertex* vertex, stack<string>& s, unordered_set<string>& set, int& x, string rootCode);
    vector<string> getPath(string origin, string dest, vector<string>& airlines);
};


#endif //AED_PROJECT2_GRAPH_H
