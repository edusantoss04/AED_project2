//
// Created by edu on 26-12-2023.
//

#include "Coordinate.h"

Coordinate::Coordinate() {

}

Coordinate::Coordinate(double latitude, double longitude) {
    latitude_=latitude;
    longitude_=longitude;
}

double Coordinate::getLatitude() {
    return latitude_;
}

double Coordinate::getLongitude() {
    return longitude_;
}
