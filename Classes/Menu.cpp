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
                 << "│  e - Exit                         │" << endl
                 << "└───────────────────────────────────┘" << endl
                 << endl
                 << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case ('1'):
                findFlights();
                return MainMenu();
            case ('2'):
                getStatistics();
                return MainMenu();
            case ('3'):
                apInfo();
                return MainMenu();
            case ('4'):
                otherInfo();
                return MainMenu();
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}


void Menu::findFlights() {
    char inputTypeO;
    cout << endl << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│            Find Flights            │" << endl
         << "├────────────────────────────────────┤" << endl
         << "│  1 - By Airport                    │" << endl
         << "│  2 - By City                       │" << endl
         << "│  3 - By Coordinates                │" << endl
         << "│  4 - By Coordinates & Radius       │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    int flag = 1;
    string inputOrigin;
    int inputRadiusO = 0;

    while(flag) {
        cout << "Choose an option: ";
        cin >> inputTypeO;

        switch(inputTypeO) {
            case ('1'):
                cout << endl << "Insert origin airport: " << endl;
                cin >> inputOrigin;
                if (data_.getAirports().find(inputOrigin) == data_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    findFlights();
                }
                flag = 0;
                break;
            case ('2'):
                cout << endl << "Insert origin city: [Format: <city>,<country> (because of repeated city names)]" << endl;
                getline(cin >>ws, inputOrigin);
                if (data_.getCities().find(inputOrigin) == data_.getCities().end()){
                    cout << "\nNot a valid city...\nTry again!\n\n";
                    findFlights();
                }
                flag = 0;
                break;
            case ('3'):
                cout << endl << "Insert origin coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;
            case ('4'):
                cout << endl << "Insert origin coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputOrigin;
                cout << endl << "Insert radius: " << endl;
                cin >> inputRadiusO;
                flag = 0;
                break;
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }

    cout << endl;
    cout << "Choose the type of destination:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - By Airport                    │" << endl
         << "│  2 - By City                       │" << endl
         << "│  3 - By Coordinates                │" << endl
         << "│  4 - By Coordinates & Radius       │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    char inputTypeD;
    string inputDestination;
    int inputRadiusD = 0;
    int flag2 = 1;
    while (flag2){
        cout << "Choose option: ";
        cin >> inputTypeD;
        switch (inputTypeD) {
            case ('1'):
                cout << endl << "Insert destination airport: " << endl;
                cin >> inputDestination;
                if (data_.getAirports().find(inputDestination) == data_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    findFlights();
                }
                flag2 = 0;
                break;

            case ('2'):
                cout << endl << "Insert destination city: [Format: <city>,<country> (because of repeated city names)]" << endl;
                getline(cin >>ws, inputDestination);
                if (data_.getCities().find(inputDestination) == data_.getCities().end()){
                    cout << "\nNot a valid city...\nTry again!\n\n";
                    findFlights();
                }
                flag2 = 0;
                break;
            case ('3'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                flag2 = 0;
                break;
            case ('4'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                flag2 = 0;
                cout << endl << "Insert radius: " << endl;
                cin >> inputRadiusD;
                break;
            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }

    cout << "Do you want an airline filter?" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  y - Yes                           │" << endl
         << "│  n - No                            │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";
    char yn;
    vector<string> filters = {};
    bool flag3 = true;
    while(flag3) {
        cout << "Choose option: ";
        cin >> yn;
        switch (yn) {
            case ('y'):
                filters = createVec();
                flag3 = 0;
                break;
            case ('n'):
                flag3 = 0;
                break;
            default:
                cout << "Not a valid option!" << endl;
        }
    }

    data_.getFlights(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48, filters,inputRadiusO ,inputRadiusD);
    back();
    return MainMenu();
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
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
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
                //countryStatistics();
                return getStatistics();
            case ('5'):
                cityStatistics();
                return getStatistics();
            case ('b'):
                return MainMenu();
            case ('e'):
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
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
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
            case ('b'):
                return;
            case ('e'):
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

    cout << "Please insert the airport code: " << endl;
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
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option: ";
        cin >> option1;

        switch (option1) {
            case ('1'):
                cout << "Number of flights: " << data_.nrFlightsOutOfAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of airlines: " << data_.nrAirlinesOutOfAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of directed cities: " << data_.nrDirectCitiesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('4'):
                cout << "Number of directed countries: " << data_.nrDirectCountriesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('5'):
                cout << "Number of directed airports: " << data_.nrDirectAirportsFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('6'):
                cout << "Number of reachable cities: " << data_.nrReachableCitiesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('7'):
                cout << "Number of reachable countries: " << data_.nrReachableCountriesFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('8'):
                cout << "Number of reachable airports: " << data_.nrReachableAirportsFromAirport(ap_code) << endl;
                back();
                return getStatistics();
            case ('b'):
                return;
            case ('e'):
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

    cout << "Please insert the airline code: " << endl;
    cin >> al_code;


     if (data_.getAirlines().find(al_code) == data_.getAirlines().end()){
        cout << "\nNot a valid airline...\nTry again!\n\n";
        airlineStatistics();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option:";
        cin >> option1;

        switch (option1) {
            case ('1'):
                cout << "Number of flights: " << data_.nrFlightsPerAirline(al_code) << endl;
                back();
                return getStatistics();
            case ('b'):
                return;
            case ('e'):
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

    getline(cin >> ws, ci_name);
    if (data_.getCities().find(ci_name) == data_.getCities().end()){
        cout << "\nNot a valid city...\nTry again!\n\n";                 // ver se funfaaaaaaaaaaa
        cityStatistics();
    }


    cout << endl << "Choose the statistic:" << endl;
    cout << "┌────────────────────────────────────┐" << endl
         << "│  1 - Total Flights                 │" << endl
         << "│  2 - Total Directed Cities         │" << endl
         << "│  3 - Total Directed Countries      │" << endl
         << "│  4 - Total Directed Airports       │" << endl
         << "│  b - Go Back                       │" << endl
         << "│  e - Exit                          │" << endl
         << "└────────────────────────────────────┘" << endl
         << endl;

    while(true) {
        cout << "Choose an option: ";
        cin >> input;

        switch (input) {
            case ('1'):
                cout << "Number of flights: " << data_.nrFlightsPerCity(ci_name, cou_name) << endl;
                back();
                return getStatistics();
            case ('2'):
                cout << "Number of directed cities: " << data_.nrDirectCitiesFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('3'):
                cout << "Number of directed countries: " << data_.nrDirectCountriesFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('4'):
                cout << "Number of directed airports: " << data_.nrDirectAirportsFromCity(ci_name) << endl;
                back();
                return getStatistics();
            case ('b'):
                return;
            case ('e'):
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
         << "│  b - Go Back                                                    │" << endl
         << "│  e - Exit                                                       │" << endl
         << "└─────────────────────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";

    while(true) {
        cout << "Choose an option: ";
        cin >> ip;

        switch (ip) {
            case ('1'):
                cout << "Please insert the origin airport code: " << endl;
                cin >> ap;

                 if (data_.getAirports().find(ap) == data_.getAirports().end()){
                    cout << "\nNot a valid airport...\nTry again!\n\n";
                    apInfo();
                }

                cout << "Insert the maximum number of flights: " << endl;
                cin >> max;
                cout << "Number of reachable airports: " << data_.MaximumXDistance(ap, max) << endl;
                back();
                return apInfo();
            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



void Menu::otherInfo() {
    char option;
    int k;
    cout << endl << endl;
    cout << "┌────────────────────────────────────────────────┐" << endl
         << "│                   Other Info                   │" << endl
         << "├────────────────────────────────────────────────┤" << endl
         << "│  1 - Airport with top-K number of flights      │" << endl
         << "│  2 - Articulation Points                       │" << endl
         << "│  3 - Maximum Trip                              │" << endl
         << "│  b - Go Back                                   │" << endl
         << "│  e - Exit                                      │" << endl
         << "└────────────────────────────────────────────────┘" << endl
         << endl
         << "What would you like to do next? ";


    while(true) {
        cout << "Choose an option: ";
        cin >> option;

        switch(option) {
            case ('1') : {
                cout << "Top-K airport with most flights? ";
                cin >> k;
                data_.maxKAirport(k);
                back();
                return otherInfo();
            }
            case ('2'):
                data_.essentialAirports();
                back();
                return otherInfo();

            case('3'):
                data_.MaximumTrip();
                back();
                return otherInfo();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option!" << endl;
        }
    }
}



vector<string> Menu::createVec() {
    bool flag = true;
    vector<string> v = {};
    cout << "Type airlines to filter and hit Enter and 'd' when done.\n\n";

    while(flag){
        string inp = "";
        cin >> inp;
        if ( inp == "d") flag = false;
        else{
            if (data_.getAirlines().find(inp) != data_.getAirlines().end())
                v.push_back(inp);
            else cout << "Not a valid airline."<< endl;
        }
    }
    cout << "Filters applied." << endl;
    return v;
}




void Menu::back() const {
    char input;
    cout << endl << endl;
    cout << "b - Back" << endl
         << "e - Exit" << endl;

    while (true){
        cout << "Choose option: ";
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

