#include "Car.h"
#include <iostream>

Car::Car() : numDoors(0) {}

Car::Car(const std::string& manu, int year, int doors) : Vehicle(manu, year), numDoors(doors) {}

void Car::setNumDoors(int doors) {
    numDoors = doors;
}

int Car::getNumDoors() const {
    return numDoors;
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Number of Doors: " << numDoors << std::endl;
}