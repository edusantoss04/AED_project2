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

    cout << d.nrReachableCountriesFromCity("Bermuda");

    //Menu menu= Menu(d);
    //menu.MainMenu();

    return 0;

}