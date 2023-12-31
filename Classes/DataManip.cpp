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

        countries_[city.second->getCountryName()]->getCities().insert(city.second->getName());

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

            auto findCities= cities_.find(city + "," + country);
            if(findCities!=cities_.end()){
                findCities->second->addAirport(code);
            }
            else{
                City *city_ = new City(city, country);

                city_->addAirport(code);
                cities_.insert({city + "," + country,city_});
            }

            Airport *airport = new Airport(code, name, city, country, latitude, longitude);
            airports_.insert({code, airport});
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
        graph_.addVertex(it->second);
        graph_.findVertex(it->second->getCode())->setIndegree(0);
        graph_.findVertex(it->second->getCode())->setOutdegree(0);
    }

    if (in.is_open()) {

        while(getline(in, line)){

            istringstream iss(line);

            getline(iss, source, ',');
            getline(iss, target, ',');
            getline(iss, airline, ',');

            Vertex* sourceVertex=graph_.findVertex(source);
            Vertex* targetVertex=graph_.findVertex(target);

            sourceVertex->setOutdegree(sourceVertex->getOutdegree()+1);
            targetVertex->setIndegree(targetVertex->getIndegree()+1);

            graph_.addEdge(source, target, airline);
        }

    } else cout << "Could not open the file\n";

}



