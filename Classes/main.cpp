#include "DataManip.h"
#include <iostream>

int main() {
    DataManip d;
    d.readAirlines();

    /*for (const auto& airline : d.getAirlines()) {
        cout << (airline.second)->getName() << endl;
    }
    cout << d.getAirlines().size();*/

    return 0;
}