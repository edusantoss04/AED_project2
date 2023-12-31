#include "DataManip.h"

using namespace std;

int main() {

    DataManip d;
    d.readAirlines();
    d.readAirports();
    d.readFlights();

    //cout << d.nrReachableAirportsFromAirport("BDA");
    //cout << d.nrReachableCountriesFromAirport("OPO");
    //cout << d.nrReachableCitiesFromAirport("OPO");

    //cout << d.MaximumXDistance("OPO", 5);
    //d.maxKAirport(1);
    d.essentialAirports();
    //cout << "314";

    return 0;

}