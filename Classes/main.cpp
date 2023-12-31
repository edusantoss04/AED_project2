#include "DataManip.h"
#include "Menu.h"

using namespace std;

int main() {

    DataManip d;
    d.readAirlines();
    d.readAirports();
    d.readFlights();
    
    Menu menu = Menu(d);
    menu.MainMenu();

    return 0;

}