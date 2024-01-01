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
    /**
 * @brief Constructor for the Menu class.
 * @param data DataManip object used for data manipulation.
 */
    Menu(DataManip data);

    /**
 * @brief Displays the main menu and handles user input.
 */
    void MainMenu();

    /**
 * @brief Handles the process of finding flights based on user input.
 */
    void findFlights();

    /**
 * @brief Handles the process of getting statistics based on user input.
 */
    void getStatistics();

    /**
 * @brief Displays and handles global statistics menu.
 */
    void globalStatistics();

    /**
 * @brief Displays and handles airport statistics menu.
 */
    void airportStatistics();

    /**
 * @brief Displays and handles airline statistics menu.
 */
    void airlineStatistics();

    /**
 * @brief Handles the process of getting city statistics based on user input.
 */
    void cityStatistics();

    /**
 * @brief Handles the process of getting information about reachable airports with a maximum number of flights based on user input.
 */
    void apInfo();

    /**
 * @brief Handles the process of getting other information based on user input.
 */
    void otherInfo();

    /**
 * @brief Creates a vector of strings based on user input to filter airlines.
 * @return A vector of strings containing airline codes as filters.
 */
    vector<string> createVec();



    /**
 * @brief Displays options to go back or exit and takes user input for further action.
 */
    void back() const;

    /**
 * @brief Exits the program.
 */
    void exitProgram() const;

};


#endif //AED_PROJECT2_MENU_H
