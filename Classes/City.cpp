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

string City::getCountry() {
    return country_;
}

void City::setName(string name) {
    name_=name;
}

void City::setCountry(string country) {
    country_=country;
}


