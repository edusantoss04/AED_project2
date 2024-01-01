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
    vector<string> parent;
    bool visited;
    bool processing;
    int indegree;
    int outdegree;
    int num;
    int distance;
    int low;

    /**
    * @brief Adds an edge to the adjacency list of the vertex.
    * @param dest The destination vertex of the edge.
    * @param airline The airline associated with the edge.
    */
    void addEdge(Vertex *dest, string airline);

public:
    /**
    * @brief Constructs a Vertex object with the given airport.
    *
    * This constructor initializes a Vertex object with the specified airport.
    *
    * @param in The airport associated with the vertex.
    */
    Vertex(Airport* in);

    /**
    * @brief Gets the airport associated with the vertex.
    * @return The airport.
    */
    Airport* getAirport() const;

    /**
    * @brief Sets the airport associated with the vertex.
    * @param in The new airport to associate with the vertex.
    */
    void setAirport(Airport* in);

    /**
    * @brief Checks if the vertex has been visited.
    * @return True if the vertex has been visited, false otherwise.
    */
    bool isVisited() const;

    /**
    * @brief Sets the visited status of the vertex.
    * @param v The new visited status.
    */
    void setVisited(bool v);

    /**
    * @brief Checks if the vertex is currently being processed.
    * @return True if the vertex is being processed, false otherwise.
    */
    bool isProcessing() const;

    /**
    * @brief Sets the processing status of the vertex.
    * @param p The new processing status.
    */
    void setProcessing(bool p);

    /**
    * @brief Gets the adjacency list of the vertex.
    * @return The adjacency list.
    */
    const vector<Edge> &getAdj() const;

    /**
    * @brief Gets the adjacency list of the vertex.
    * @return The adjacency list.
    */
    int getIndegree() const;

    /**
    * @brief Sets the indegree of the vertex.
    * @param indegree The new indegree of the vertex.
    */
    void setIndegree(int indegree);

    /**
    * @brief Gets the outdegree of the vertex.
    * @return The outdegree of the vertex.
    */
    int getOutdegree() const;

    /**
    * @brief Sets the outdegree of the vertex.
    * @param outdegree The new outdegree of the vertex.
    */
    void setOutdegree(int outdegree);


    /**
    * @brief Gets the numeric identifier of the vertex.
    * @return The numeric identifier of the vertex.
    */
    int getNum() const;

    /**
    * @brief Sets the numeric identifier of the vertex.
    * @param num The new numeric identifier of the vertex.
    */
    void setNum(int num);


    /**
    * @brief Gets the low value of the vertex.
    * @return The low value of the vertex.
    */
    int getLow() const;

    /**
    * @brief Sets the low value of the vertex.
    * @param low The new low value of the vertex.
    */
    void setLow(int low);


    /**
    * @brief Sets the low value of the vertex.
    * @param low The new low value of the vertex.
    */
    int getdistance();

    /**
    * @brief Sets the distance associated with the vertex.
    * @param distance The new distance associated with the vertex.
    */
    void setDistance(int distance);

    friend class Graph;
};

class Edge {
    Vertex * dest;      // destination vertex
    string airline ;         // edge weight
public:

    /**
    * @brief Constructs an Edge object with the given destination vertex and airline.
    *
    * This constructor initializes an Edge object with the specified destination vertex and airline.
    *
    * @param d The destination vertex of the edge.
    * @param airline The airline associated with the edge.
    */
    Edge(Vertex *d, string airline);

    /**
    * @brief Gets the destination vertex of the edge.
    * @return The destination vertex.
    */
    Vertex *getDest() const;

    /**
    * @brief Gets the airline associated with the edge.
    * @return The airline associated with the edge.
    */
    string getAirline() const;

    friend class Graph ;
    friend class Vertex ;
};


class Graph {
    unordered_map<string, Vertex *> vertexSet;

public:

    /**
    * @brief Finds a vertex with the given airport code in the graph.
    *
    * This method searches for a vertex with the specified airport code in the graph.
    *
    * @param airportCode The code of the airport to search for.
    * @return A pointer to the found vertex, or nullptr if not found.
    */
    Vertex *findVertex(const string &airportCode) const;

    /**
    * @brief Adds a new vertex to the graph with the given airport information.
    *
    * This method adds a new vertex to the graph if a vertex with the same airport code doesn't already exist.
    *
    * @param in The airport information to create the new vertex.
    * @return True if the vertex was added successfully, false if a vertex with the same code already exists.
    */
    bool addVertex(Airport *in);

    /**
    * @brief Adds a new directed edge between two vertices in the graph with the given airline information.
    *
    * This method adds a new directed edge from the source vertex to the destination vertex with the specified airline information.
    *
    * @param sourcCode The code of the source airport.
    * @param destCode The code of the destination airport.
    * @param airline The airline information associated with the edge.
    * @return True if the edge was added successfully, false if either the source or destination vertex is not found.
    */
    bool addEdge(const string &sourcCode, const string &destCode, const string &airline);


    /**
    * @brief Gets the set of vertices in the graph.
    *
    * This method returns an unordered map containing the airport codes as keys and corresponding vertices as values.
    *
    * @return The set of vertices in the graph.
    */
    unordered_map<string, Vertex *> getVertexSet() const;


    /**
    * @brief Performs Breadth-First Search (BFS) starting from a specified airport code.
    *
    * This method traverses the graph using BFS starting from the specified airport code,
     * counting the number of unique airports, cities, and countries visited during the traversal.
    *
    * @param airportCode The code of the starting airport for BFS.
    * @return A vector containing the counts of unique airports, countries, and cities visited during BFS.
    */
    vector<int> bfs(const string &airportCode) const;


    /**
    * @brief Performs Breadth-First Search (BFS) with a limited number of stops from a specified airport code.
    *
    * This method traverses the graph using BFS starting from the specified airport code,
            * counting the number of unique airports, cities, and countries visited during the traversal,
    * with a maximum number of stops (k) allowed.
    *
    * @param airportCode The code of the starting airport for BFS.
    * @param k The maximum number of stops allowed in the BFS traversal.
    * @return A vector containing the counts of unique airports, countries, and cities visited during BFS with limited stops.
    */
    vector<int> bfsStops(const string &airportCode, int k) const;

    /**
    * @brief Performs Breadth-First Search (BFS) to find shortest paths from a specified airport code.
    *
    * This method uses BFS to find the shortest paths from the specified airport code to all other airports in the graph.
    *
    * @param airportCode The code of the starting airport for BFS.
    */
    void bfsPath(const string &airportCode);


    /**
    * @brief Performs Breadth-First Search (BFS) with airline filters to find shortest paths from a specified airport code.
    *
    * This method uses BFS to find the shortest paths from the specified airport code to all other airports in the graph,
    * considering only edges with specified airline filters.
    *
    * @param airportCode The code of the starting airport for BFS.
    * @param airlines A vector of airline codes to filter the paths.
    */
    void bfsWithFilters(const string &airportCode, vector<string> &airlines);


    /**
    * @brief Performs Depth-First Search (DFS) to find articulation points in the graph.
    *
    * This method uses DFS to find articulation points in the graph and updates a set with the identified points.
    *
    * @param vertex The current vertex being processed in DFS.
    * @param s A stack to keep track of the vertices in the current DFS path.
    * @param set A set to store the identified articulation points.
    * @param x A reference to the numbering counter for vertices.
     * @param rootNode The code of the root node of the DFS traversal.
    */
    void dfsArt(Vertex *vertex, stack<string> &s, unordered_set<string> &set, int &x, string rootCode);

    /**
    * @brief Finds and prints all paths from an origin airport to a destination airport with optional airline filters.
    *
    * This method uses BFS with optional airline filters to find paths from the origin airport to the destination airport
    * and then utilizes a recursive approach to find all possible paths. The paths are printed, and the unique paths are returned.
    *
    * @param origin The code of the origin airport.
    * @param dest The code of the destination airport.
    * @param airlines A vector of airline codes to filter the paths (empty vector for no filtering).
    * @return A vector of vectors representing all unique paths from the origin to the destination.
    */
    vector<vector<string>> getPath(const string& origin, const string& dest, vector<string>& airlines);

    /**
    * @brief Recursively finds all paths from a current airport to a destination airport in the graph.
    *
    * This method uses a recursive depth-first search (DFS) approach to find all paths from the current airport
            * to the destination airport in the graph and stores them in the given vector of vectors.
    *
    * @param current The code of the current airport in the search path.
    * @param dest The code of the destination airport.
    * @param currentPath A vector representing the current path being explored.
    * @param allPaths A vector of vectors to store all the paths from the current airport to the destination.
    */
    void findAllPaths(const string& current, const string& dest, vector<string>& currentPath, vector<vector<string>>& allPaths);
};

#endif //AED_PROJECT2_GRAPH_H
