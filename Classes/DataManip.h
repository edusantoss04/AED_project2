#ifndef AED_PROJECT2_DATAMANIP_H
#define AED_PROJECT2_DATAMANIP_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

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
    int nrFlightsOutOfAirport(const string& airportCode);
    int nrAirlinesOutOfAirport(const string& airportCode);

    int nrDirectCitiesFromAirport(const string& airportCode);
    int nrDirectAirportsFromAirport(const string& airportCode);
    int nrDirectCountriesFromAirport(const string& airportCode);

    int nrReachableAirportsFromAirport(const string& airportCode);
    int nrReachableCountriesFromAirport(const string& airportCode);
    void dfsVisitCountriesFromAirport(Vertex *v, set<string> &res);
    int nrReachableCitiesFromAirport(const string& airportCode);
    void dfsVisitCitiesFromAirport(Vertex *v, set<string> &res);

    //Airline Statictis
    int nrFlightsPerAirline(const string& airlineCode);

    //Country Statistics

    //City Statistics
    int nrFlightsPerCity(const string& city, const string& country);
    int nrDirectCitiesFromCity(const string& city);
    int nrDirectAirportsFromCity(const string& city);
    int nrDirectCountriesFromCity(const string& cityName);


    //Airport Info
    int MaximumXDistance(const string& airportCode, int k);

    //Other info
    pair<set<pair<string,string>>,int> MaximumTrip();
    pair<string,int> maxKAirport(int k);
    unordered_set<string> essentialAirports();

    //Auxiliar functions
    static bool sortTopKAirports(pair<string, int> a,  pair<string, int> b);

    //Flighs Manager functions
    void getFlights(string origin, string dest, int oType, int dType, vector<string>& filters , int oRadius, int dRadius );
    vector<string> getAirportsInCity(string CityPlusCountry);

    string getClosestAirport(string coordinate);
    vector<string> getAirportsNearLocation(string coordinate,double radius);

};


#endif //AED_PROJECT2_DATAMANIP_H
