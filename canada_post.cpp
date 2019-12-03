// Copyright (c) 2019 Christina Ngwa All rights reserved.
//
// Created by: Christina Ngwa
// Created on: November 2019
// This program formats mailing addresses according to Canada Post

#include <iostream>
#include <string>

std::string CanadaPost(std::string name, std::string street, std::string city,
                      std::string province, std::string postal,
                      std::string aptNum = "") {
    // This program formats mailing addresses according to canada post
    std::string formatted;

    // Process
    if (aptNum.size() != 0) {
        formatted = name + "\n" + aptNum + "-" + street + "\n" + city +
                    " " + province + "  " + postal;
    } else {
        formatted = name + "\n" + street + "\n" + city + " " + province +
                    "  " + postal;
    }
    return formatted;
}

int main() {
    // Gets user's details to format for mailing

    // Variables
    std::string userName;
    std::string userStreet;
    std::string question;
    std::string userCity;
    std::string userProvince;
    std::string userPostal;
    std::string formattedAddress;
    std::string userAptNum = "";

    // Output
    std::cout << "Welcome to the Canada Post address formatter." << std::endl;
    std::cout << "For validity, please input with precision "
                 "(upper case is ideal)." << std::endl;
    std::cout << std::endl;

    // Input
    std::cout << "Enter full name: ";
    std::getline(std::cin, userName);
    std::cout << "Does recipient live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y" || question == "yes" || question == "Y"
        || question == "YES") {
        std::cout << "Enter apartment number: ";
        std::getline(std::cin, userAptNum);
    }
    std::cout << "Enter street name and number: ";
    std::getline(std::cin, userStreet);
    std::cout << "Enter city: ";
    std::getline(std::cin, userCity);
    std::cout << "Enter province/territory: ";
    std::getline(std::cin, userProvince);
    std::cout << "Enter postal code: ";
    std::getline(std::cin, userPostal);

    // Process
    if (userAptNum != "") {
        formattedAddress = CanadaPost(userName, userStreet, userCity,
                              userProvince, userPostal, userAptNum);
    } else {
        formattedAddress = CanadaPost(userName, userStreet, userCity,
                              userProvince, userPostal);
    }

    // Output
    std::cout << "" << std::endl;
    std::cout << "Formatted:" << std::endl;
    std::cout << formattedAddress << std::endl;
}
