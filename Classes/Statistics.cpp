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
    for (Vertex *vertex: graph_.getVertexSet()){
        nr_flights += vertex->getAdj().size();
    }

    return nr_flights;
}


//Airport Statistics
int DataManip::nrFlightsOfAirport(const string& airportCode){
    return graph_.findVertex(airportCode)->getAdj().size();
}

int DataManip::nrReachableCitiesFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);
    set<string> cities_names;

    for (Edge edg: vertex->getAdj()){

        cities_names.insert(edg.getDest()->getAirport()->getCity());
    }

    return cities_names.size();
}

int DataManip::nrReachableAirportsFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);

    return vertex->getAdj().size();
}

int DataManip::nrAirlinesOfAirport(const std::string &airportCode) {
    Vertex* SourceAirport = graph_.findVertex(airportCode);
    set<string> Airlines;
    for(auto v: SourceAirport->getAdj()){
        Airlines.insert(v.getAirline());
    }
    return Airlines.size();
}

int DataManip::nrReachableCountriesFromAirport(const string &airportCode) {
    Vertex* SourceAirport = graph_.findVertex(airportCode);
    set<string> reachableCountries;
    for(auto v: SourceAirport->getAdj()){
        string city_ = v.getDest()->getAirport()->getCity();
        City *destCity= cities_[city_];
        reachableCountries.insert(destCity->getCountryName());
    }
    return reachableCountries.size();
}

//Airline Statictis
int DataManip::nrFlightsPerAirline(const string& airlineCode){

    int nr_flights = 0;
    for (Vertex *vertex: graph_.getVertexSet()){

            for (Edge edg: vertex->getAdj()){

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

    for (Vertex *vertex: graph_.getVertexSet()){

        if(vertex->getAirport()->getCity() == city){
            nr_flights += vertex->getAdj().size();
        }
    }

    for (Vertex *vertex: graph_.getVertexSet()){

        if(vertex->getAirport()->getCity() != city){

            for (Edge edg: vertex->getAdj()){

                if (edg.getDest()->getAirport()->getCity() == city){
                    nr_flights++;
                }
            }
        }
    }

    return nr_flights;
}

int DataManip::nrReachableCitiesFromCity(const string& city){

    set<string> cities_names;

    for (Vertex *vertex: graph_.getVertexSet()){

        if(vertex->getAirport()->getCity() == city){

            for (Edge edg: vertex->getAdj()){

                cities_names.insert(edg.getDest()->getAirport()->getCity());

            }
        }
    }

    return cities_names.size();
}

int DataManip::nrReachableAirportsFromCity(const string& city){

    set<string> airports;

    for (Vertex *vertex: graph_.getVertexSet()){

        if(vertex->getAirport()->getCity() == city){

            for (Edge edg: vertex->getAdj()){

                airports.insert(edg.getDest()->getAirport()->getCode());

            }
        }
    }

    return airports.size();
}

int DataManip::nrReachableCountriesFromCity(const std::string &cityName) {
    set <Vertex*> airports;

    // Select all airports in cityName
    for(auto v : graph_.getVertexSet()){
        if(v->getAirport()->getCity()==cityName){
            airports.insert(v);
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

