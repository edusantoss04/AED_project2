
#ifndef AED_PROJECT2_CITY_H
#define AED_PROJECT2_CITY_H
#include <string>
#include <unordered_set>

using namespace std;

class City {
    private:
    string name_;
    string country_;
    unordered_set<string> airports;
public:
    City(string& name,string& country);

    string getName();
    string getCountryName();

    void setName(string name);
    void setCountry(string country);

    const unordered_set<string> &getAirports() const;
    void addAirport(const string &airportCode);
    void setAirports(const unordered_set<string> &airports);
};


#endif //AED_PROJECT2_CITY_H
