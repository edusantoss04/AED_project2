#ifndef AED_PROJECT2_CITY_H
#define AED_PROJECT2_CITY_H

#include <string>
#include <unordered_set>

using namespace std;

/**
 * @class City
 * @brief Represents a city with its name, country, and associated airports.
 */
class City {
    private:
    string name_;
    string country_;
    unordered_set<string> airports;
public:

    /**
    * @brief Constructs a City object with the given name and country.
    *
    * This constructor initializes a City object with the specified name and country.
    *
    * @param name The name of the city.
    * @param country The country where the city is located.
    */
    City(string& name,string& country);

    /**
    * @brief Gets the name of the city.
    * @return The name of the city.
    */
    string getName();

    /**
    * @brief Gets the country where the city is located.
    * @return The country of the city.
    */
    string getCountryName();

    /**
    * @brief Sets the name of the city.
    * @param name The new name of the city.
    */
    void setName(string name);

    /**
    * @brief Sets the country where the city is located.
    * @param country The new country of the city.
    */
    void setCountry(string country);

    /**
    * @brief Gets the set of airport codes associated with the city.
    * @return The set of airport codes.
    */
    const unordered_set<string> &getAirports() const;

    /**
    * @brief Adds an airport code to the set associated with the city.
    * @param airportCode The airport code to add.
    */
    void addAirport(const string &airportCode);

    /**
    * @brief Sets the set of airport codes associated with the city.
    * @param airports The new set of airport codes.
    */
    void setAirports(const unordered_set<string> &airports);
};


#endif //AED_PROJECT2_CITY_H
