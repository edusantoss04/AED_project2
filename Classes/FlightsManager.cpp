#include "DataManip.h"
void DataManip::getFlights(string origin, string dest, int oType, int dType, vector<string>& filters , int oRadius = 0, int dRadius = 0){
    vector<string> originAirp = {};
    vector<string> destAirp = {};
    vector<vector<string>> Paths = {};
    switch (oType) {
        case 1: originAirp.push_back(origin); break;
        case 2: //originAirp = ir buscar os aeroportos da cidade origin
        case 3: break; //originAirp = ir buscar os aeroportos perto das coordenadas (origin contem x.(...),y.(...) e oRadius contem os graus

    }
    switch (dType) {
        case 1: destAirp.push_back(dest); break;
        case 2: break;//originAirp = ir buscar os aeroportos da cidade dest
        case 3: break; //originAirp = ir buscar os aeroportos perto das coordenadas (dest contem x.(...),y.(...) e dRadius contem os graus

    }

     for(auto o : originAirp){
         for( auto d : destAirp){
             //vector<string> a = graph_.getPath(o,d,filters); //implementar getPath no Graph
         }
     }
}

