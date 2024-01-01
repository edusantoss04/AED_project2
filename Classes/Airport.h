#ifndef AED_PROJECT2_AIRPORT_H
#define AED_PROJECT2_AIRPORT_H
#include <iostream>
#include <string>
#include "Coordinate.h"

using namespace std;

class Airport {
    private:
        string code_;
        string name_;
        string city_;
        string country_;
        Coordinate coordinate_;
    public:
    /**
    * @brief Constructs an Airport object with the given parameters.
    *
    * This constructor initializes an Airport object with the specified code, name, city, country, and coordinates.
    *
    * @param code The airport code.
    * @param name The name of the airport.
    * @param city The city where the airport is located.
    * @param country The country where the airport is situated.
    * @param latitude The latitude coordinate of the airport.
    * @param longitude The longitude coordinate of the airport.
    */
    Airport(string& code, string& name,string& city, string & country, double latitude,double longitude);

    Airport();

    /**
    * @brief Gets the airport code.
    * @return The airport code.
    */
    string getCode();

    /**
    * @brief Gets the name of the airport.
    * @return The airport name.
    */
    string getName();

    /**
    * @brief Gets the city where the airport is located.
    * @return The city of the airport.
    */
    string getCity();

    /**
    * @brief Gets the country where the airport is situated.
    * @return The country of the airport.
    */
    string getCountry();

    /**
    * @brief Gets the coordinates of the airport.
    * @return The coordinates of the airport.
    */
    Coordinate getCoordinate();

    /**
    * @brief Sets the airport code.
    * @param code The new airport code.
    */
    void setCode(string& code);

    /**
    * @brief Sets the name of the airport.
    * @param name The new airport name.
     */
    void setName(string& name);

    /**
    * @brief Sets the city where the airport is located.
    * @param city The new city of the airport.
    */
    void setCity(string& city);

    /**
    * @brief Sets the country where the airport is situated.
    * @param country The new country of the airport.
    */
    void setCountry(string& country);

    /**
    * @brief Sets the coordinates of the airport.
    * @param latitude The new latitude coordinate.
    * @param longitude The new longitude coordinate.
    */
    void setCoordinate(double latitude,double longitude);

    /**
    * @brief Equality operator for comparing two Airport objects.
    *
    * This operator checks whether two Airport objects are equal based on their code, name, city, country,
    * and coordinates.
    *
    * @param other The Airport object to compare with.
    * @return True if the objects are equal, false otherwise.
    */
    bool operator==(Airport other);

};


#endif //AED_PROJECT2_AIRPORT_H
