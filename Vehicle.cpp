#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() : yearBuilt(0) {}

Vehicle::Vehicle(const std::string& manu, int year) : manufacturer(manu), yearBuilt(year) {}

void Vehicle::setManufacturer(const std::string& manu) {
    manufacturer = manu;
}

std::string Vehicle::getManufacturer() const {
    return manufacturer;
}

void Vehicle::setYearBuilt(int year) {
    yearBuilt = year;
}

int Vehicle::getYearBuilt() const {
    return yearBuilt;
}

void Vehicle::displayInfo() const {
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "Year Built: " << yearBuilt << std::endl;
}