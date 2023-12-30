#include "DataManip.h"
#include "Menu.h"
#include "Graph.h"
#include <iostream>

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
    d.MaximumTrip();

    return 0;

}