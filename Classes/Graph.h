//
// Created by pedrosspedro on 22-12-2023.
//

#ifndef AED_PROJECT2_GRAPH_H
#define AED_PROJECT2_GRAPH_H


#include <cstddef>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include "Airport.h"
using namespace std;

class Edge;
class Graph;
class Vertex;


/****************** Provided structures  ********************/

class Vertex {
    Airport* airport;                // contents
    vector<Edge> adj;
    string parent;         // list of outgoing edges
    bool visited;          // auxiliary field
    bool processing;       // auxiliary field
    int indegree;          // auxiliary field
    int outdegree;         // auxiliary field
    int num;               // auxiliary field
    int distance;           // auxiliary field
    int low;               // auxiliary field

    void addEdge(Vertex *dest, string airline);
    //bool removeEdgeTo(Vertex *d);
public:
    Vertex(Airport* in);
    Airport* getAirport() const;
    void setAirport(Airport* in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge> &getAdj() const;
    //void setAdj(const vector<Edge> &adj);

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
    //void setDest(Vertex *dest);
    string getAirline() const;
    //void setWeight(double weight);
    friend class Graph ;
    friend class Vertex ;
};


class Graph {
    unordered_map<string, Vertex*> vertexSet;      // vertex set
    int _index_;                        // auxiliary field
    stack<Vertex> _stack_;           // auxiliary field
    //list<list> _list_sccs_;        // auxiliary field

    void dfsVisit(Vertex *v,vector<Airport> & res) const;
    bool dfsIsDAG(Vertex *v) const;
public:
    Vertex *findVertex(const string& airportCode) const;
    int getNumVertex() const;
    bool addVertex(Airport *in);
    bool addEdge(const string& sourcCode, const string& destCode, const string& airline);
    //bool removeVertex(const Airport &in);
    //bool removeEdge(const Airport &sourc, const Airport &dest);
    unordered_map<string, Vertex*> getVertexSet() const;
    //vector<Airport>dfs() const;
    //vector<Airport> dfs(Airport &airport) const;
    vector<int> bfs(const string& airportCode)const;
    vector<int> bfsStops(const string& airportCode, int k)const;
    void bfsPath(const string& airportCode);
    void bfsWithFilters(const string& airportCode, vector<string>& airlines);
    vector<Airport> topsort() const;
    bool isDAG() const;

    void dfsArt(Vertex* vertex, stack<string>& s, unordered_set<string>& set, int& x, string rootCode);
    vector<string> getPath(string origin, string dest, vector<string>& airlines);
};


#endif //AED_PROJECT2_GRAPH_H
