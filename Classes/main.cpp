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

    Menu menu= Menu(d);
    menu.MainMenu();

    /*for (const auto& airline : d.getAirlines()) {
        cout << (airline.second)->getName() << endl;
    }
    cout << d.getAirlines().size();

    for (auto airport: d.getAirports()) {
        cout << airport.second->getCode() << endl;
    }
    cout << d.getAirports().size();
*/
    cout <<d.getAirports().size();
    return 0;

}