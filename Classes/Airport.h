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
        Coordinate coordinate_;
    public:
    Airport(string& code, string& name,string& city,double latitude,double longitude);
    string getCode();
    string getName();
    string getCity();
    Coordinate getCoordinate();
    void setCode(string& code);
    void setName(string& name);
    void setCity(string& city);
    void setCoordinate(double latitude,double longitude);

    bool operator==(Airport other);

};


#endif //AED_PROJECT2_AIRPORT_H
