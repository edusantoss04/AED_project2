#include <algorithm>
#include "DataManip.h"
#include "Graph.h"


//Global Statistics
int DataManip::nrAirports(){
    return airports_.size();
}

int DataManip::nrAirlines(){
    return airlines_.size();
}

int DataManip::nrFlights(){

    int nr_flights = 0;
    for (auto vertex: graph_.getVertexSet()){
        nr_flights += vertex.second->getAdj().size();
    }

    return nr_flights;
}


//Airport Statistics
int DataManip::nrFlightsOutOfAirport(const string& airportCode){

    return graph_.findVertex(airportCode)->getAdj().size();

}

int DataManip::nrDirectCitiesFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);
    set<string> cities_names;

    for (Edge edg: vertex->getAdj()){

        cities_names.insert(edg.getDest()->getAirport()->getCity());
    }

    return cities_names.size();
}

int DataManip::nrDirectAirportsFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);
    set<string> airports;

    for (auto edg: vertex->getAdj()){

        airports.insert(edg.getDest()->getAirport()->getCode());
    }

    return airports.size();
}

int DataManip::nrAirlinesOutOfAirport(const std::string &airportCode) {
    Vertex* SourceAirport = graph_.findVertex(airportCode);
    set<string> Airlines;
    for(auto v: SourceAirport->getAdj()){
        Airlines.insert(v.getAirline());
    }
    return Airlines.size();
}

int DataManip::nrDirectCountriesFromAirport(const string &airportCode) {
    Vertex* SourceAirport = graph_.findVertex(airportCode);
    set<string> reachableCountries;
    for(auto v: SourceAirport->getAdj()){
        reachableCountries.insert(v.getDest()->getAirport()->getCountry());
    }
    return reachableCountries.size();
}

int DataManip::nrReachableAirportsFromAirport(const string& airportCode){
    return graph_.bfs(airportCode)[0];
}

int DataManip::nrReachableCountriesFromAirport(const string& airportCode){

    set<string> countries;
    auto vertex = graph_.findVertex(airportCode);

    for(auto vertex: graph_.getVertexSet()){
        vertex.second->setVisited(false);
    }

    dfsVisitCountriesFromAirport(vertex, countries);
    return countries.size();
}

void DataManip::dfsVisitCountriesFromAirport(Vertex *v, set<string> &res){


    v->setVisited(true);
    res.insert(v->getAirport()->getCountry());

    for (Edge edj: v->getAdj()){
        auto w = edj.getDest();
        if (!w->isVisited()){
            dfsVisitCountriesFromAirport(w, res);
        }
    }
}

int DataManip::nrReachableCitiesFromAirport(const string& airportCode){

    set<string> cities;
    auto vertex = graph_.findVertex(airportCode);

    for(auto vertex: graph_.getVertexSet()){
        vertex.second->setVisited(false);
    }

    dfsVisitCitiesFromAirport(vertex, cities);
    return cities.size();
}

void DataManip::dfsVisitCitiesFromAirport(Vertex *v, set<string> &res){


    v->setVisited(true);
    res.insert(v->getAirport()->getCity());

    for (Edge edj: v->getAdj()){
        auto w = edj.getDest();
        if (!w->isVisited()){
            dfsVisitCitiesFromAirport(w, res);
        }
    }
}


//Airline Statictis
int DataManip::nrFlightsPerAirline(const string& airlineCode){

    int nr_flights = 0;
    for (auto vertex: graph_.getVertexSet()){

            for (Edge edg: vertex.second->getAdj()){

                if (edg.getAirline() == airlineCode){
                    nr_flights++;
                }
            }
        }

    return nr_flights;
}

//Country Statistics


//City Statistics
int DataManip::nrFlightsPerCity(const string& city, const string& country){

    int nr_flights = 0;
    auto vec = cities_[city]->getAirports();

    for(auto v : vec){
        auto vertex = graph_.getVertexSet()[v];
        nr_flights += vertex->getAdj().size();
        nr_flights += vertex->getIndegree();
    }



    return nr_flights;
}

int DataManip::nrDirectCitiesFromCity(const string& city){

    set<string> cities_names;

    for (auto vertex: graph_.getVertexSet()){

        if(vertex.second->getAirport()->getCity() == city){

            for (Edge edg: vertex.second->getAdj()){

                cities_names.insert(edg.getDest()->getAirport()->getCity());

            }
        }
    }

    return cities_names.size();
}

int DataManip::nrDirectAirportsFromCity(const string& city){

    set<string> airports;

    for (auto vertex: graph_.getVertexSet()){

        if(vertex.second->getAirport()->getCity() == city){

            for (Edge edg: vertex.second->getAdj()){

                airports.insert(edg.getDest()->getAirport()->getCode());

            }
        }
    }

    return airports.size();
}

int DataManip::nrDirectCountriesFromCity(const std::string &cityNamePlusCountry) {
    int sum=0;
    for(auto airportCode : cities_[cityNamePlusCountry]->getAirports()){
        sum+= graph_.bfs(airportCode)[1]; // [1] to get Countries;
    }
    return sum;
}


//Airport Info
int DataManip::MaximumXDistance(const string& airportCode, int k) {

    cout << "Number of reachable: " << endl;
    cout << endl << "Airports: " << graph_.bfsStops(airportCode, k)[0] << endl;
    cout << "Countries: " << graph_.bfsStops(airportCode, k)[1] << endl;
    cout << "Cities: " << graph_.bfsStops(airportCode, k)[2] << endl;
}
//Other info
pair<set<pair<string,string>>,int> DataManip::MaximumTrip(){
    set<pair<string,string>> vec;
    int maxTrip=0;

    for(auto airport: graph_.getVertexSet()){
        for(auto v:graph_.getVertexSet()){
            v.second->setVisited(false);
            v.second->setDistance(-1);
        }

        queue<Vertex*> queue1;
        auto vertex= graph_.findVertex(airport.first);
        queue1.push(vertex);
        queue1.front()->setVisited(true);
        queue1.front()->setDistance(0);

        while(!queue1.empty()){
            Vertex* v = queue1.front();
            queue1.pop();
            for(auto edg:v->getAdj()){

                auto w= edg.getDest();

                if(!w->isVisited()){
                    w->setDistance((v->getdistance()+1));
                    queue1.push(w);
                    w->setVisited(true);
                    if (w->getdistance() >= maxTrip) {
                        if (w->getdistance() > maxTrip) {
                            vec.clear();
                            maxTrip = w->getdistance();
                        }
                        vec.insert({airport.first, w->getAirport()->getCode()});
                    }
                }
            }
        }
    }
    cout << endl << "Max trip: "<< maxTrip << endl << endl;
    for (auto r:vec){
        cout << r.first << "-->" << r.second << endl;
    }

    pair<set<pair<string,string>>,int> a = {vec,maxTrip};
    return a;
}


pair<string,int> DataManip::maxKAirport(int k){
    vector<pair<string,int>> vec;
    for (auto vertex : graph_.getVertexSet()){
        int sum=0;
        sum+=vertex.second->getOutdegree() + vertex.second->getIndegree();
        vec.push_back({vertex.second->getAirport()->getName(),sum});
    }
    sort(vec.begin(),vec.end(), sortTopKAirports);

    pair<string, int> topKVec;
    topKVec= vec[k-1];
    cout << endl << "Top-" << k << " airport with most flights is " << topKVec.first << " with " << topKVec.second << " flights.";
    return topKVec;
}


bool DataManip::sortTopKAirports(pair<string, int> a,pair<string, int> b){
    if(a.second > b.second) return true;
    else if (a.second == b.second){
       return a.first < b.first;
    }
    return false;
}

Graph makeUndirectedGraph(Graph graph);
unordered_set<string> DataManip::essentialAirports(){

    Graph copy = makeUndirectedGraph(graph_);

    for (auto v: copy.getVertexSet()){
        v.second->setVisited(false);
    }

    int x = 1;
    unordered_set<string> set;
    stack<string> stk;

    for (auto v: copy.getVertexSet()){

        if(!v.second->isVisited()){
            copy.dfsArt(v.second, stk, set, x, v.first);
        }
    }

    cout << endl << "Number of essential airports: " << set.size();

    return set;
}

/**
 * @brief Helper function to create an undirected copy of the graph.
 * @param graph The original graph.
 * @return An undirected copy of the original graph.
 */
Graph makeUndirectedGraph(Graph graph){

    for ( auto v: graph.getVertexSet()){

        for ( auto edg: v.second->getAdj()){
            auto w = edg.getDest();
            graph.addEdge(w->getAirport()->getCode(), v.second->getAirport()->getCode(),"");
        }
    }
    return graph;
}