//
// Created by edu on 26-12-2023.
//

#ifndef AED_PROJECT2_COORDINATE_H
#define AED_PROJECT2_COORDINATE_H


class Coordinate {
    private:
        double latitude_;
        double longitude_;

    public:
    Coordinate();
    Coordinate(double latitude, double longitude);
    double getLatitude();
    double getLongitude();

};


#endif //AED_PROJECT2_COORDINATE_H
