#include <cmath>
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

double Coordinate::DistanceBetCoordinates(Coordinate cord2) const {
    const double earthRadius = 6371000;
    double lat1= cord2.getLatitude() * M_PI / 180.0;
    double lat = latitude_ * M_PI / 180.0;

    double distLonRad = (cord2.getLongitude()* M_PI / 180.0 - longitude_* M_PI / 180.0);
    double distLatRad = (cord2.getLatitude()* M_PI / 180.0 - latitude_* M_PI / 180.0);

    double b = pow(sin(distLatRad  / 2), 2) + pow(sin(distLonRad / 2), 2) * cos(lat) * cos(lat1);
    double c = 2 * asin(sqrt(b));

    return c*earthRadius;
}
