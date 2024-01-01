#include "DataManip.h"
void DataManip::getFlights(string origin, string dest, int oType, int dType, vector<string>& filters , int oRadius = 0, int dRadius = 0){
    vector<string> originAirp = {};
    vector<string> destAirp = {};
    vector<vector<string>> paths = {};
    switch (oType) {
        case 1: originAirp.push_back(origin); break;
        case 2: originAirp = getAirportsInCity(origin); break;
        case 3: originAirp.push_back(getClosestAirport(origin)); break;
        case 4: originAirp = getAirportsNearLocation(origin,oRadius); break;

    }
    switch (dType) {
        case 1: destAirp.push_back(dest); break;
        case 2: destAirp= getAirportsInCity(dest); break;
        case 3: destAirp.push_back(getClosestAirport(dest)); break;
        case 4: destAirp = getAirportsNearLocation(dest,dRadius); break;

    }

     for(auto o : originAirp){
         for( auto d : destAirp){
             vector<vector<string>> a = graph_.getPath(o,d,filters);
             if(!a.empty()){
                 paths=a;
             }
         }
     }
     if(paths.empty()){
         cout<< "No flights available from "<< origin << " to " << dest << "..." << endl;
     }

}
vector<string> DataManip::getAirportsInCity(string CityPlusCountry){
    vector<string> res;
    unordered_set<string> Temp = cities_[CityPlusCountry]->getAirports();
    for(auto value : Temp){
        res.push_back(value);
    }
    return res;
}

string DataManip::getClosestAirport(string coordinate){
    string v = ",";
    size_t pos = coordinate.find(v);
    Coordinate co = Coordinate(stod(coordinate.substr(0, pos)), stod(coordinate.substr(pos+1)));
    string closestAirpCode;
    double minDistance = HUGE_VAL;
    for(auto airport: airports_){
        double distance = co.DistanceBetCoordinates(airport.second->getCoordinate());
        if(distance<minDistance){
            minDistance= distance;
            closestAirpCode= airport.first;
        }
    }
    return closestAirpCode;
}

vector<string> DataManip::getAirportsNearLocation(string coordinate,double radius){
    string v = ",";
    size_t pos = coordinate.find(v);
    Coordinate co = Coordinate(stod(coordinate.substr(0, pos)), stod(coordinate.substr(pos+1)));
    vector<string> res;
    for(auto airport:airports_){
        double distance= co.DistanceBetCoordinates(airport.second->getCoordinate());
        if(distance<=radius){
            res.push_back(airport.first);
        }
    }
    return res;
}