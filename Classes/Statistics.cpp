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

}


//Airport Statistics
int DataManip::nrFlightsOfAirport(const string& airportCode){
    return graph_.findVertex(airportCode)->getAdj().size();
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


//Country Statistics


//City Statistics
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