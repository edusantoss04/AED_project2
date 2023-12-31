//
// Created by edu on 26-12-2023.
//

#include "City.h"


City::City(string& name,string& country) {
    name_=name;
    country_=country;
}

string City::getName() {
    return name_;
}

string City::getCountryName() {
    return country_;
}

void City::setName(string name) {
    name_=name;
}

void City::setCountry(string country) {
    country_=country;
}

const unordered_set<string> &City::getAirports() const {
    return airports;
}

void City::addAirport(const string &airportCode) {
    airports.insert(airportCode);
}

void City::setAirports(const unordered_set<string> &airports) {
    this->airports = airports;
}


