#ifndef AED_PROJECT2_AIRLINES_H
#define AED_PROJECT2_AIRLINES_H

#include <iostream>

using namespace std;

class Airline{

private:
    string code_;
    string name_;
    string callSign_;
    string country_;

public:
    Airline(string code, string name, string callSign, string country);

    string getCode();
    string getName();
    string getCallSign();
    string getCountry();

    void setCode(string code);
    void setName(string name);
    void setCallSign(string callSign);
    void setCountry(string country);
};



#endif //AED_PROJECT2_AIRLINES_H
