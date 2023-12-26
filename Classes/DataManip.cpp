#include "DataManip.h"

DataManip::DataManip() {}

unordered_map<string,  Airport*> DataManip::getAirports() {
    return airports_;
}

unordered_map<string, Airline*> DataManip::getAirlines() {
    return airlines_;
}

unordered_map<string, City*> DataManip::getCities() {
    return cities_;
}

unordered_map<string, Country*> DataManip::getCountries() {
    return countries_;
}

Graph DataManip::getGraph(){
    return graph_;
}

void DataManip::createCountries() {

    for (auto city: cities_){

        countries_[city.second->getCountry()]->getCities().insert(city.second->getName());

    }
}

void DataManip::readAirlines() {

    ifstream in("../dataset/airlines.csv");
    string line, code, name, callSign, countryName;
    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, code, ',');
            getline(iss, name, ',');
            getline(iss, callSign, ',');
            getline(iss, countryName, ',');

            Airline *airline = new Airline(code, name, callSign, countryName);
            airlines_.insert({code, airline});

        }

    } else cout << "Could not open the file\n";

}

void DataManip::readAirports() {

    ifstream in("../dataset/airports.csv");
    string line, code, name, city, country;
    double latitude, longitude;
    getline(in, line);

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, code, ',');
            getline(iss, name, ',');
            getline(iss, city, ',');
            getline(iss, country, ',');
            iss >> latitude;
            iss.ignore();
            iss >> longitude;

            City *city_ = new City(city, country);
            Airport *airport = new Airport(code, name, city, latitude, longitude);
            airports_.insert({code, airport});
            cities_.insert({city,city_});
            countries_.insert({country, new Country(country)});

        }

    } else cout << "Could not open the file\n";

    createCountries();

}

void DataManip::readFlights() {

    ifstream in("../dataset/flights.csv");
    string line, source, target, airline;
    getline(in, line);

    for (auto it = airports_.begin(); it != airports_.end(); it++){
        graph_.addVertex(*it->second);
    }

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, source, ',');
            getline(iss, target, ',');
            getline(iss, airline, ',');

            graph_.addEdge(*airports_[source], *airports_[target], airline);

        }

    } else cout << "Could not open the file\n";

}


