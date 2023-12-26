//
// Created by sofia on 26-12-2023.
//

#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(DataManip data) {
    data_ = data;
}

void Menu::MainMenu() {
    char option;
    cout << endl << endl;
    cout << endl << "┌───────────────────────────────────┐" << endl
                 << "│             Main Menu             │" << endl
                 << "├───────────────────────────────────┤" << endl
                 << "│  1 - Find Flights                 │" << endl
                 << "│  2 - Get Statistics               │" << endl
                 << "│  3 - Airport Info                 │" << endl
                 << "│  4 - Other Info                   │" << endl
                 << "│  5 - Exit                         │" << endl
                 << "└───────────────────────────────────┘" << endl
                 << endl
                 << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case '1':
                findFlights();
                return MainMenu();

            case '2':
                getStatistics();
                return MainMenu();

            case '3':
                apInfo();
                return MainMenu();

            case '4':
                otherInfo();
                return MainMenu();

            case '5':
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}


void Menu::findFlights() {
    char input;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│            Find Flights            │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - By Airport                    │" << endl
         << "│  2 - By City                       │" << endl
         << "│  3 - By Country                    │" << endl
         << "│  4 - By Coordinates                │" << endl
         << "│  5 - Go Back                       │" << endl
         << "│  6 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";
}








void Menu::getStatistics() {
    char option1;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│           Get Statistics           │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - Global                        │" << endl
         << "│  2 - Airport                       │" << endl
         << "│  3 - Airline                       │" << endl
         << "│  4 - Country                       │" << endl
         << "│  5 - City                          │" << endl
         << "│  6 - Go Back                       │" << endl
         << "│  7 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> option1;

        switch(option1) {
            case ('1'):
                globalStatistics();
                return getStatistics();
            case ('2'):
                airportStatistics();
                return getStatistics();
            case ('3'):
                airlineStatistics();
                return getStatistics();
            case ('4'):
                countryStatistics();
                return getStatistics();
            case ('5'):
                cityStatistics();
                return getStatistics();
            case ('6'):
                return MainMenu();
            case ('7'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}


void Menu::globalStatistics() {
    char option;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│          Global Statistics         │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - Total Airports                │" << endl
         << "│  2 - Total Airlines                │" << endl
         << "│  3 - Total Flights                 │" << endl
         << "│  4 - Total Countries               │" << endl
         << "│  5 - Total Cities                  │" << endl
         << "│  6 - Go Back                       │" << endl
         << "│  7 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1'):
                // cout << "Number of airports: " << data_.totalAirports() << endl;
                back();
                return getStatistics();
            case ('2'):
                // cout << "Number of airlines: " << data_.totalAirlines() << endl;
                back();
                return getStatistics();
            case ('3'):
                // cout << "Number of flights: " << data_.totalFlights() << endl;
                back();
                return getStatistics();
            case ('4'):
                // cout << "Number of countries: " << data_.totalCountries() << endl;
                back();
                return getStatistics();
            case ('5'):
                // cout << "Number of cities: " << data_.totalCities() << endl;
                back();
                return getStatistics();
            case ('6'):
                return;
            case ('7'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}

void Menu::airportStatistics() {
    char option1;
    string ap_code;
    cout << "┌────────────────────────────────────┐" << endl
         << "│         Airport Statistics         │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    cout << "Please insert the airport code:" << endl;
    cin >> ap_code;

    /*
     if (d_.getAirports().find(ap) == d_.getAirports().end()){
        cout << "\nNot a valid airport...\nTry again!\n\n";
        airportStatistic();
    }
     */

    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  2 - Total Airlines                │" << endl
         << "│  3 - Total Destinations            │" << endl
         << "│  4 - Go Back                       │" << endl
         << "│  5 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while (true){
        cout << "Choose an option:";
        cin >> option1;

        switch (option1) {
            case ('1'):
                // cout << "Number of flights:" << d_.nFlights3(ap) << endl;
                back();
                return getStatistics();
            case ('2'):
                // cout << "Number of airlines:" << d_.nAirlines3(ap) << endl;
                back();
                return getStatistics();
            case ('3'):
                // cout << "Number of destinations:" << d_.nDestinations3(ap) << endl;
                back();
                return getStatistics();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}












































void Menu::back() const {
    char input;
    cout << endl << endl;
    cout << "b - Back" << endl
         << "e - Exit" << endl;

    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}

void Menu::exitProgram() const {
    cout << endl << "Exiting program..." << endl;
    exit(0);
}

