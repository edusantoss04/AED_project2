#include "Airport.h"

Airport::Airport(string& code, string& name, string& city,double latitude,double longitude) {
    code_=code;
    name_=name;
    city_=city;
    coordinate_= Coordinate(latitude,longitude);
}

string Airport::getCode() {
    return code_;
}

string Airport::getName() {
    return name_;
}

string Airport::getCity() {
    return city_;
}

void Airport::setCode(string& code) {
    code_= code;
}

void Airport::setName(string& name) {
    name_= name;
}

void Airport::setCity(string& city) {
    city_ = city;
}

Coordinate Airport::getCoordinate() {
    return coordinate_;
}

void Airport::setCoordinate(double latitude, double longitude) {
    coordinate_=Coordinate(latitude,longitude);
}

bool Airport::operator==(Airport other) {
    return code_ == other.code_ &&
            name_ == other.name_ &&
            city_ == other.city_ &&
            coordinate_.getLatitude() == other.coordinate_.getLatitude() &&
            coordinate_.getLongitude() == other.coordinate_.getLongitude();
}

Airport::Airport() {
}





