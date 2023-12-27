#ifndef AED_PROJECT2_DATAMANIP_H
#define AED_PROJECT2_DATAMANIP_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


#include <unordered_map>
#include "Airport.h"
#include "Airline.h"
#include "City.h"
#include "Coordinate.h"
#include "Country.h"
#include "Graph.h"


using namespace std;

class DataManip {

private:
    unordered_map<string,  Airport*> airports_;
    unordered_map<string, Airline*> airlines_;
    unordered_map<string, City*> cities_;
    unordered_map<string, Country*> countries_;
    Graph graph_;

public:
    DataManip();
    unordered_map<string,  Airport*> getAirports();
    unordered_map<string, Airline*> getAirlines();
    unordered_map<string, City*> getCities();
    unordered_map<string, Country*> getCountries();
    Graph getGraph();

    void readAirlines();
    void readAirports();
    void readFlights();

    void createCountries();

    //Statistics

    //Global Statistics
    int nrAirports();
    int nrAirlines();
    int nrFlights();
    int nrCountries();
    int nrCities();

    //Airport Statistics
    int nrFlightsOfAirport(const string& airportCode);

    //Airline Statictis

    //Country Statistics

    //City Statistics

};


#endif //AED_PROJECT2_DATAMANIP_H
