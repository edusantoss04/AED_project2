#include <set>
#include <string>

#ifndef AED_PROJECT2_COUNTRY_H
#define AED_PROJECT2_COUNTRY_H

using namespace std;

/**
 * @class Country
 * @brief Represents a country with its name and associated cities.
 */
class Country {
private:
    string name_;
    set<string> cities_;
public:
    /**
     * @brief Constructor for the Country class.
     * @param name The name of the country.
     */
    Country(string& name);

    /**
     * @brief Gets the name of the country.
     * @return The name of the country.
     */
    string getName();

    /**
     * @brief Gets the set of cities in the country.
     * @return A set containing the names of cities in the country.
     */
    set<string> getCities();
};


#endif //AED_PROJECT2_COUNTRY_H
