#ifndef AED_PROJECT2_AIRLINE_H
#define AED_PROJECT2_AIRLINE_H

#include <iostream>

using namespace std;

/**
 * @class Airline
 * @brief Represents an airline with its code, name, call sign, and country.
 */
class Airline{

private:
    string code_;
    string name_;
    string callSign_;
    string country_;

public:
    /**
 * @brief Constructor for the Airline class.
 * @param code The airline code.
 * @param name The name of the airline.
 * @param callSign The call sign of the airline.
 * @param country The country of the airline.
 */
    Airline(string code, string name, string callSign, string country);

    /**
 * @brief Getter function for the airline code.
 * @return The airline code.
 */
    string getCode();

    /**
 * @brief Getter function for the name of the airline.
 * @return The name of the airline.
 */
    string getName();

    /**
 * @brief Getter function for the call sign of the airline.
 * @return The call sign of the airline.
 */
    string getCallSign();

    /**
 * @brief Getter function for the country of the airline.
 * @return The country of the airline.
 */
    string getCountry();

    /**
 * @brief Setter function for the airline code.
 * @param code The new airline code.
 */
    void setCode(string code);

    /**
 * @brief Setter function for the name of the airline.
 * @param name The new name of the airline.
 */
    void setName(string name);

    /**
 * @brief Setter function for the call sign of the airline.
 * @param callSign The new call sign of the airline.
 */
    void setCallSign(string callSign);

    /**
 * @brief Setter function for the country of the airline.
 * @param country The new country of the airline.
 */
    void setCountry(string country);
};



#endif //AED_PROJECT2_AIRLINE_H
