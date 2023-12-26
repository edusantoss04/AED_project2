#include "DataManip.h"
#include <iostream>

int main() {
    DataManip d;
    d.readAirlines();
    d.readAirports();
    d.readFlights();

    /*for (const auto& airline : d.getAirlines()) {
        cout << (airline.second)->getName() << endl;
    }
    cout << d.getAirlines().size();*/

    for (auto airport: d.getAirports()) {
        cout << airport.second->getName() << endl;
    }
    cout << d.getAirports().size();


    return 0;
}