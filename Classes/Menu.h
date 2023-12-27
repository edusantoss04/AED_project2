//
// Created by sofia on 26-12-2023.
//

#ifndef AED_PROJECT2_MENU_H
#define AED_PROJECT2_MENU_H


#include "DataManip.h"

class Menu {

private:
    DataManip data_;

public:
    Menu(DataManip data);
    void MainMenu();


    void findFlights();
    void getStatistics();
    void globalStatistics();
    void airportStatistics();
    void airlineStatistics();
    void countryStatistics();
    void cityStatistics();
    void apInfo();
    void otherInfo();




    void back() const;
    void exitProgram() const;

};


#endif //AED_PROJECT2_MENU_H
