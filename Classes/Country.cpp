//
// Created by edu on 26-12-2023.
//

#include "Country.h"


Country::Country(std::string &name) {
    name_ = name;
}

string Country::getName() {
    return name_;
}

set<string> Country::getCities() {
    return cities_;
}



