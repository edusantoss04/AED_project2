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

/**
 * @class DataManip
 * @brief Class for manipulating and managing data related to airports, airlines, cities, countries, and flight information.
 */
class DataManip {

private:
    unordered_map<string,  Airport*> airports_;
    unordered_map<string, Airline*> airlines_;
    unordered_map<string, City*> cities_;
    unordered_map<string, Country*> countries_;
    Graph graph_;

public:

    /**
     * @brief Default constructor.
     */
    DataManip();

    /**
    * @brief Getter function for airports.
    * @return The unordered map of airports.
    */
    unordered_map<string,  Airport*> getAirports();

    /**
     * @brief Getter function for airlines.
     * @return The unordered map of airlines.
     */
    unordered_map<string, Airline*> getAirlines();

    /**
     * @brief Getter function for cities.
     * @return The unordered map of cities.
     */
    unordered_map<string, City*> getCities();

    /**
    * @brief Getter function for countries.
    * @return The unordered map of countries.
    */
    unordered_map<string, Country*> getCountries();

    /**
     * @brief Getter function for the graph.
     * @return The graph representing flight connections.
     */
    Graph getGraph();

    /**
     * @brief Reads airline information from a CSV file.
     */
    void readAirlines();

    /**
     * @brief Reads airport information from a CSV file.
     */
    void readAirports();

    /**
     * @brief Reads flight information from a CSV file and constructs the flight graph.
     */
    void readFlights();

    /**
    * @brief Creates countries based on the cities in the data.
    */
    void createCountries();

    //Statistics

    //Global Statistics

    /**
     * @brief Gets the total number of airports in the dataset.
    * @return The total number of airports.
     */
    int nrAirports();

    /**
 * @brief Gets the total number of airlines in the dataset.
 * @return The total number of airlines.
 */
    int nrAirlines();

    /**
 * @brief Gets the total number of flights in the dataset.
 * @return The total number of flights.
 */
    int nrFlights();
    int nrCountries();
    int nrCities();

    //Airport Statistics

    /**
     * @brief Calculates the number of flights leaving a given airport.
     * @param airportCode The code of the airport.
     * @return The number of flights leaving the specified airport.
     */
    int nrFlightsOutOfAirport(const string& airportCode);

    /**
 * @brief Gets the number of airlines operating flights from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of airlines operating flights from the specified airport.
 */
    int nrAirlinesOutOfAirport(const string& airportCode);

    /**
 * @brief Gets the number of direct cities reachable from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of direct cities reachable from the specified airport.
 */
    int nrDirectCitiesFromAirport(const string& airportCode);

    /**
 * @brief Gets the number of direct airports reachable from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of direct airports reachable from the specified airport.
 */
    int nrDirectAirportsFromAirport(const string& airportCode);

    /**
 * @brief Gets the number of direct countries reachable from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of direct countries reachable from the specified airport.
 */
    int nrDirectCountriesFromAirport(const string& airportCode);

    /**
 * @brief Gets the number of reachable airports from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of reachable airports from the specified airport.
 */
    int nrReachableAirportsFromAirport(const string& airportCode);

    /**
 * @brief Gets the number of reachable countries from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of reachable countries from the specified airport.
 */
    int nrReachableCountriesFromAirport(const string& airportCode);

/**
 * @brief Visits countries reachable from a specific airport using depth-first search.
 * @param v The starting vertex.
 * @param res The set to store the visited countries.
 */
    void dfsVisitCountriesFromAirport(Vertex *v, set<string> &res);

    /**
 * @brief Gets the number of reachable cities from a specific airport.
 * @param airportCode The code of the airport.
 * @return The number of reachable cities from the specified airport.
 */
    int nrReachableCitiesFromAirport(const string& airportCode);

    /**
 * @brief Visits cities reachable from a specific airport using depth-first search.
 * @param v The starting vertex.
 * @param res The set to store the visited cities.
 */
    void dfsVisitCitiesFromAirport(Vertex *v, set<string> &res);

    //Airline Statictis

    /**
 * @brief Gets the number of flights operated by a specific airline.
 * @param airlineCode The code of the airline.
 * @return The number of flights operated by the specified airline.
 */
    int nrFlightsPerAirline(const string& airlineCode);

    //Country Statistics

    //City Statistics

    /**
 * @brief Gets the total number of flights related to a specific city within a country.
 * @param city The name of the city.
 * @param country The name of the country.
 * @return The total number of flights related to the specified city within the specified country.
 */
    int nrFlightsPerCity(const string& city, const string& country);

    /**
 * @brief Gets the number of direct cities reachable from a specific city.
 * @param city The name of the city.
 * @return The number of direct cities reachable from the specified city.
 */
    int nrDirectCitiesFromCity(const string& city);

    /**
 * @brief Gets the number of direct airports reachable from a specific city.
 * @param city The name of the city.
 * @return The number of direct airports reachable from the specified city.
 */
    int nrDirectAirportsFromCity(const string& city);

    /**
 * @brief Gets the number of direct countries reachable from a specific city.
 * @param cityNamePlusCountry The combined name of the city and country (e.g., "New York, USA").
 * @return The number of direct countries reachable from the specified city.
 */
    int nrDirectCountriesFromCity(const string& cityName);


    //Airport Info
    /**
 * @brief Computes and prints the number of reachable airports, countries, and cities from a specified airport within a given distance.
 * @param airportCode The code of the source airport.
 * @param k The maximum distance for reachability.
 */
    int MaximumXDistance(const string& airportCode, int k);

    //Other info
    /**
 * @brief Finds the maximum trip (number of stops) from any airport to any other airport and prints the details.
 * @return A pair containing the set of pairs representing the maximum trip and the maximum number of stops.
 */
    pair<set<pair<string,string>>,int> MaximumTrip();

    /**
 * @brief Finds and prints the top-K airports with the most combined in-degree and out-degree.
 * @param k The number of top airports to find.
 * @return A pair containing the airport code and the total degree for the top-K airport.
 */
    pair<string,int> maxKAirport(int k);

/**
 * @brief Creates an undirected copy of the graph to be used for essential airports computation.
 * @param graph The original graph.
 * @return An undirected copy of the original graph.
 */
    unordered_set<string> essentialAirports();

    //Auxiliar functions
    /**
 * @brief Helper function to compare two pairs of airports based on their degrees for sorting.
 * @param a The first pair.
 * @param b The second pair.
 * @return True if the degree of the first pair is greater, or if degrees are equal, compares the airport names.
 */
    static bool sortTopKAirports(pair<string, int> a,  pair<string, int> b);


    //Flighs Manager functions

    /**
    * @brief Retrieves flights based on specified origin and destination parameters.
    *
    * This method retrieves flights based on the origin and destination parameters, along with optional filters and radius constraints.
    * It uses the graph to find paths between airports and considers different types of origin and destination specifications.
    *
    * @param origin The origin location or airport code.
    * @param dest The destination location or airport code.
    * @param oType The type of origin specification (1: Airport Code, 2: City, 3: Closest Airport, 4: Near Location).
    * @param dType The type of destination specification (1: Airport Code, 2: City, 3: Closest Airport, 4: Near Location).
    * @param filters A vector of airline codes to filter the paths.
    * @param oRadius The radius for origin specification (default: 0 for Airport Code or City).
    * @param dRadius The radius for destination specification (default: 0 for Airport Code or City).
    */
    void getFlights(string origin, string dest, int oType, int dType, vector<string>& filters , int oRadius, int dRadius );

    /**
    * @brief Retrieves airports in a specified city plus country combination.
    *
    * This method retrieves airports in the specified city plus country combination using the associated City object.
    *
    * @param CityPlusCountry The combined string representing the city plus country.
    * @return A vector of airport codes in the specified city plus country.
    */
    vector<string> getAirportsInCity(string CityPlusCountry);


    /**
    * @brief Retrieves the closest airport to a specified coordinate.
    *
    * This method calculates the distance between the specified coordinate and all airports, returning the code of the closest airport.
    *
    * @param coordinate The string representation of the coordinate in the format "latitude,longitude".
    * @return The airport code of the closest airport to the specified coordinate.
    */
    string getClosestAirport(string coordinate);

    /**
    * @brief Retrieves airports within a specified radius of a given coordinate.
    *
    * This method calculates the distance between the specified coordinate and all airports,
    * returning a vector of airport codes within the specified radius.
    *
    * @param coordinate The string representation of the coordinate in the format "latitude,longitude".
    * @param radius The maximum distance from the specified coordinate to consider airports.
    * @return A vector of airport codes within the specified radius of the given coordinate.
    */
    vector<string> getAirportsNearLocation(string coordinate,double radius);

};


#endif //AED_PROJECT2_DATAMANIP_H
