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
        string city_ = v.getDest()->getAirport()->getCity();
        City *destCity= cities_[city_];
        reachableCountries.insert(destCity->getCountryName());
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

    for (auto vertex: graph_.getVertexSet()){

        if(vertex.second->getAirport()->getCity() == city){
            nr_flights += vertex.second->getAdj().size();
        }
    }

    for (auto vertex: graph_.getVertexSet()){

        if(vertex.second->getAirport()->getCity() != city){

            for (Edge edg: vertex.second->getAdj()){

                if (edg.getDest()->getAirport()->getCity() == city){
                    nr_flights++;
                }
            }
        }
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

int DataManip::nrDirectCountriesFromCity(const std::string &cityName) {
    set <Vertex*> airports;

    // Select all airports in cityName
    for(auto v : graph_.getVertexSet()){
        if(v.second->getAirport()->getCity()==cityName){
            airports.insert(v.second);
        }
    }
    // Select all different countries reachable from selected airports
    set<string> reachableCountries;
    for(auto a: airports){
        for(auto e: a->getAdj()){ //destinos do aeroporto
            string city_= e.getDest()->getAirport()->getCity(); // cidade de destino
            City *destCity= cities_[city_];
            reachableCountries.insert(destCity->getCountryName());
        }
    }

    return reachableCountries.size();
}


//Airport Info
int DataManip::MaximumXDistance(const string& airportCode, int k) {

    return graph_.bfsStops(airportCode, k)[0];
}
//Other info
pair<set<pair<string,string>>,int> DataManip::MaximumTrip(){
    set<pair<string,string>> vec;
    int maxTrip=0;

    for(auto airport: graph_.getVertexSet()){
        for(auto v:graph_.getVertexSet()){
            v.second->setVisited(false);
            v.second->setNum(-1);
        }

        queue<Vertex*> queue1;
        auto vertex= graph_.findVertex(airport.first);
        queue1.push(vertex);
        queue1.front()->setVisited(true);
        queue1.front()->setNum(0);

        while(!queue1.empty()){
            Vertex* v = queue1.front();
            queue1.pop();
            for(auto edg:v->getAdj()){

                auto w= edg.getDest();

                if(!w->isVisited()){
                    w->setNum((v->getNum()+1));
                    queue1.push(w);
                    w->setVisited(true);
                    if (w->getNum() >= maxTrip) {
                        if (w->getNum() > maxTrip) {
                            vec.clear();
                            maxTrip = w->getNum();
                        }
                        vec.insert({airport.first, w->getAirport()->getCode()});
                    }
                }
            }
        }
    }
    cout << "max trip: "<< maxTrip <<endl;
    for (auto r:vec){
        cout<< r.first << "-->" << r.second<<endl;
    }

    pair<set<pair<string,string>>,int> a = {vec,maxTrip};
    return a;
}