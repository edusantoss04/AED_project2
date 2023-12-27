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


//Airline Statictis


//Country Statistics


//City Statistics
