#include <set>
#include <string>

#ifndef AED_PROJECT2_COUNTRY_H
#define AED_PROJECT2_COUNTRY_H

using namespace std;
class Country {
private:
    string name_;
    set<string> cities_;
public:
    Country(string& name);
    Country();
    string getName();
    set<string> getCities();
};


#endif //AED_PROJECT2_COUNTRY_H
