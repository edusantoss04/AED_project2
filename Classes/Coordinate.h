#ifndef AED_PROJECT2_COORDINATE_H
#define AED_PROJECT2_COORDINATE_H

/**
 * @class Coordinate
 * @brief Represents a geographical coordinate (latitude and longitude).
 */
class Coordinate {
    private:
        double latitude_;
        double longitude_;

    public:
    /**
     * @brief Default constructor. Initializes latitude and longitude to 0.
     */
    Coordinate();

    /**
     * @brief Parameterized constructor.
     * @param latitude The latitude of the coordinate.
     * @param longitude The longitude of the coordinate.
     */
    Coordinate(double latitude, double longitude);

    /**
     * @brief Getter function for latitude.
     * @return The latitude of the coordinate.
     */
    double getLatitude();

    /**
     * @brief Getter function for longitude.
     * @return The longitude of the coordinate.
     */
    double getLongitude();

    /**
     * @brief Calculates the great-circle distance between two coordinates.
     * @param cord2 The second coordinate.
     * @return The distance between the coordinates in meters.
     */
    double DistanceBetCoordinates(Coordinate cord2) const;

};


#endif //AED_PROJECT2_COORDINATE_H
