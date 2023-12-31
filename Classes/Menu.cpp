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
         << "│  4 - Go Back                       │" << endl
         << "│  5 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1'):
                cout << "Number of airports: " << data_.nrAirports() << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of airlines: " << data_.nrAirlines() << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of flights: " << data_.nrFlights() << endl;
                back();
                return getStatistics();
            case ('4'):
                return;
            case ('5'):
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


     if (data_.getAirports().find(ap_code) == data_.getAirports().end()){
        cout << "\nNot a valid airport...\nTry again!\n\n";                       // reveeerrrrrrrrrr
        airportStatistics();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  2 - Total Airlines                │" << endl
         << "│  3 - Total Directed Cities         │" << endl
         << "│  4 - Total Directed Countries      │" << endl
         << "│  5 - Total Directed Airports       │" << endl
         << "│  6 - Total Reachable Cities        │" << endl
         << "│  7 - Total Reachable Countries     │" << endl
         << "│  8 - Total Reachable Airports      │" << endl
         << "│  9 - Go Back                       │" << endl
         << "│  10 - Exit                         │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option:";
        cin >> option1;

        switch (option1) {
            case ('1'):
                cout << "Number of flights:" << data_.nrFlightsOutOfAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of airlines:" << data_.nrAirlinesOutOfAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of directed cities:" << data_.nrDirectCitiesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('4'):
                cout << "Number of directed countries:" << data_.nrDirectCountriesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('5'):
                cout << "Number of directed airports:" << data_.nrDirectAirportsFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('6'):
                cout << "Number of reachable cities:" << data_.nrReachableCitiesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('7'):
                cout << "Number of reachable countries:" << data_.nrReachableCountriesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('8'):
                cout << "Number of reachable airports:" << data_.nrReachableAirportsFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('9'):
                return;
            case ('10'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



void Menu::airlineStatistics() {
    char option1;
    string al_code;
    cout << "┌────────────────────────────────────┐" << endl
         << "│         Airline Statistics         │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    cout << "Please insert the airline code:" << endl;
    cin >> al_code;


     if (data_.getAirlines().find(al_code) == data_.getAirlines().end()){
        cout << "\nNot a valid airline...\nTry again!\n\n";
        airlineStatistics();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  2 - Go Back                       │" << endl
         << "│  3 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option:";
        cin >> option1;

        switch (option1) {
            case ('1'):
                cout << "Number of flights:" << data_.nrFlightsPerAirline(al_code) << endl;
                back();
                return getStatistics();
            case ('2'):
                return;
            case ('3'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



/*
void Menu::countryStatistics() {
    char input;
    string cn_name;
    cout << "┌────────────────────────────────────┐" << endl
         << "│         Country Statistics         │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    cout << "Please insert the name of the country:" << endl;
    cin >> cn_name;


    string c;
    getline(cin >>ws, c);
     if (d_.getCountries().find(c) == d_.getCountries().end()){
        cout << "\nNot a valid country...\nTry again!\n\n";
        countryStatistic();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Cities                  │" << endl
         << "│  2 - Total Airports                │" << endl
         << "│  3 - Total Airlines                │" << endl
         << "│  4 - Total Flights                 │" << endl
         << "│  5 - Total Destinations            │" << endl
         << "│  6 - Go Back                       │" << endl
         << "│  7 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option:";
        cin >> input;

        switch (input) {
            case ('1'):
                // cout << "Number of cities:" << d_.nCities(c) << endl;
                back();
                return getStatistics();
            case ('2'):
                // cout << "Number of airports:" << d_.nAirports(c) << endl;
                back();
                return getStatistics();
            case ('3'):
                // cout << "Number of airlines:" << d_.nAirlines(c) << endl;
                back();
                return getStatistics();
            case ('4'):
                // cout << "Number of flights:" << d_.nFlights(c) << endl;
                back();
                return getStatistics();
            case ('5'):
                // cout << "Number of destinations:" << d_.nDestinations(c) << endl;
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

*/

void Menu::cityStatistics() {
    char input;
    string ci_name;
    string cou_name;
    cout << "┌────────────────────────────────────┐" << endl
         << "│          City Statistics           │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    cout << "Please insert the name of the city: (Format: <city>,<country> because of repeated city names) " << endl;

    getline(cin >> ci_name, cou_name);
    if (data_.getCities().find(cou_name) == data_.getCities().end()){
        cout << "\nNot a valid city...\nTry again!\n\n";                 // ver se funfaaaaaaaaaaa
        cityStatistics();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  2 - Total Directed Cities         │" << endl
         << "│  3 - Total Directed Countries      │" << endl
         << "│  4 - Total Directed Airports       │" << endl
         << "│  5 - Go Back                       │" << endl
         << "│  6 - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option:";
        cin >> input;

        switch (input) {
            case ('1'):
                cout << "Number of flights:" << data_.nrFlightsPerCity(ci_name, cou_name) << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of directed cities:" << data_.nrDirectCitiesFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of directed countries:" << data_.nrDirectCountriesFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('4'):
                cout << "Number of directed airports:" << data_.nrDirectAirportsFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('5'):
                return;
            case ('6'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}




void Menu::apInfo() {
    char ip;
    string ap;
    int max;
    cout << "┌─────────────────────────────────────────────────────────────────┐" << endl
         << "│                          Airport Info                           │" << endl
         << "├─────────────────────────────────────────────────────────────────┤" << endl
         << "│  1 - Number of reachable airports with maximum of X flights     │" << endl
         << "│  2 - Go Back                                                    │" << endl
         << "│  3 - Exit                                                       │" << endl
         << "└─────────────────────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> ip;

        switch (ip) {
            case ('1'):
                cout << "Please insert the origin airport code:" << endl;
                cin >> ap;

                 if (data_.getAirports().find(ap) == data_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    apInfo();
                }

                cout << "Insert the maximum number of flights:" << endl;
                cin >> max;
                cout << "Number of reachable airports: " << data_.MaximumXDistance(ap, max) << endl;
                back();
                return apInfo();
            case ('2'):
                return;

            case ('3'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



void Menu::otherInfo() {
    char option;
    string k;
    cout << endl << endl;
    cout << "┌────────────────────────────────────────────────┐" << endl
         << "│                   Other Info                   │" << endl
         << "├────────────────────────────────────────────────┤" << endl
         << "│  1 - Airports with top-K number of flights     │" << endl
         << "│  2 - Articulation Points                       │" << endl
         << "│  3 - Go Back                                   │" << endl
         << "│  4 - Exit                                      │" << endl
         << "└────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1'):
                cout << "How many airports with most flights? ";
                cin >> k;
                cout << "Top-" << k << " airports with most flights: " ;
                /*
                for (auto a: d_.topKairports(stoi(k))){
                    cout << a << " | " ;
                }
                */
                cout << endl;
                back();
                return otherInfo();
            case ('2'):

                // fazeeeeeeeeerrrrrrrrrrrrrr


                back();
                return otherInfo();
            case ('3'):
                return;
            case ('4'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
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

