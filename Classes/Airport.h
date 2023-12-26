#ifndef AED_PROJECT2_AIRPORT_H
#define AED_PROJECT2_AIRPORT_H
#include <iostream>
#include <string>
using namespace std;

class Airport {
    private:
        string code;
        string name;
        string city;
        //Coordinate coordinate;
    public:
    Airport(string code, string name,string city);
    string getCode();
    string getName();
    string getCity();
    void setCode(string code);
    void setName(string name);
    void setCity(string city);

};


#endif //AED_PROJECT2_AIRPORT_H
