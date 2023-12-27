
#ifndef AED_PROJECT2_CITY_H
#define AED_PROJECT2_CITY_H
#include <string>

using namespace std;

class City {
    private:
    string name_;
    string country_;
public:
    City(string& name,string& country);

    string getName();
    string getCountryName();

    void setName(string name);
    void setCountry(string country);
};


#endif //AED_PROJECT2_CITY_H
