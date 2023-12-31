#include "DataManip.h"
#include "Menu.h"
using namespace std;

int main() {

    DataManip d;
    d.readAirlines();
    d.readAirports();
    d.readFlights();

    //Menu menu = Menu(d);
    //menu.MainMenu();
    //cout << d.nrDirectCountriesFromAirport("OPO");
    //cout << d.nrReachableAirportsFromAirport("BDA");
    //cout << d.nrReachableCountriesFromAirport("OPO");
    //cout << d.nrReachableCitiesFromAirport("OPO");

    //cout << d.MaximumXDistance("OPO", 5);
    //d.maxKAirport(1);
    //d.essentialAirports();
    //cout << "314";
    vector<string> a = {"IBE"};
    d.getFlights("OPO","PDL",1,1,a,0,0);

    return 0;

}