#include "Airport.h"

Airport::Airport(string code, string name, string city) {
    this->code=code;
    this->name=name;
    this->city=city;
}

string Airport::getCode() {
    return this->code;
}

string Airport::getName() {
    return this->name;
}

string Airport::getCity() {
    return this->city;
}

void Airport::setCode(string code) {
    this->code=code;
}

void Airport::setName(string name) {
    this->name=name;
}

void Airport::setCity(string city) {
    this->city=city;
}





