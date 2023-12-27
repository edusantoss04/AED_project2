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
    int nrAirlinesOfAirport(const string& airportCode);

    int nrReachableCitiesFromAirport(const string& airportCode);
    int nrReachableAirportsFromAirport(const string& airportCode);
    int nrReachableCountriesFromAirport(const string& airportCode);

    //Airline Statictis
    int nrFlightsPerAirline(const string& airlineCode);

    //Country Statistics

    //City Statistics
    int nrFlightsPerCity(const string& city, const string& country);
    int nrReachableCitiesFromCity(const string& city);
    int nrReachableAirportsFromCity(const string& city);
    int nrReachableCountriesFromCity(const string& cityName);

};


#endif //AED_PROJECT2_DATAMANIP_H
