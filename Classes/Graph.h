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
#include "Airport.h"
using namespace std;

class Edge;
class Graph;
class Vertex;


/****************** Provided structures  ********************/

class Vertex {
    Airport* airport;                // contents
    vector<Edge> adj;  // list of outgoing edges
    bool visited;          // auxiliary field
    bool processing;       // auxiliary field
    int indegree;          // auxiliary field
    int num;               // auxiliary field
    int low;               // auxiliary field

    void addEdge(Vertex *dest, double w);
    bool removeEdgeTo(Vertex *d);
public:
    Vertex(Airport in);
    Airport getInfo() const;
    void setInfo(Airport in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge> &getAdj() const;
    void setAdj(const vector<Edge> &adj);

    int getIndegree() const;

    void setIndegree(int indegree);

    int getNum() const;

    void setNum(int num);

    int getLow() const;

    void setLow(int low);

    friend class Graph;
};

class Edge {
    Vertex * dest;      // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex *d, double w);
    Vertex *getDest() const;
    void setDest(Vertex *dest);
    double getWeight() const;
    void setWeight(double weight);
    friend class Graph ;
    friend class Vertex ;
};


class Graph {
    vector<Vertex *> vertexSet;      // vertex set
    int _index_;                        // auxiliary field
    stack<Vertex> _stack_;           // auxiliary field
    //list<list> _list_sccs_;        // auxiliary field

    void dfsVisit(Vertex *v,vector<Airport> & res) const;
    bool dfsIsDAG(Vertex *v) const;
public:
    Vertex *findVertex(const Airport &in) const;
    int getNumVertex() const;
    bool addVertex(const Airport &in);
    bool removeVertex(const Airport &in);
    bool addEdge(const Airport &sourc, const Airport &dest, double w);
    bool removeEdge(const Airport &sourc, const Airport &dest);
    vector<Vertex* > getVertexSet() const;
    vector<Airport>dfs() const;
    vector<Airport> dfs(const Airport & source) const;
    vector<Airport> bfs(const Airport &source) const;
    vector<Airport> topsort() const;
    bool isDAG() const;
};


#endif //AED_PROJECT2_GRAPH_H
