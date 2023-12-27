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

int DataManip::nrCitiesFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);
    set<string> cities_names;

    for (Edge edg: vertex->getAdj()){

        cities_names.insert(edg.getDest()->getAirport()->getCity());
    }

    return cities_names.size();
}

int DataManip::nrAirportsFromAirport(const string& airportCode){

    Vertex* vertex = graph_.findVertex(airportCode);

    return vertex->getAdj().size();
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
int DataManip::nrFlightsPerCity(const string& city){

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

int DataManip::nrCitiesFromCity(const string& city){

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

int DataManip::nrAirportsFromCity(const string& city){

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
