#include "Truck.h"
#include <iostream>

Truck::Truck() : towingCapacity(0.0) {}

Truck::Truck(const std::string& manu, int year, double capacity) : Vehicle(manu, year), towingCapacity(capacity) {}

void Truck::setTowingCapacity(double capacity) {
    towingCapacity = capacity;
}

double Truck::getTowingCapacity() const {
    return towingCapacity;
}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << "Towing Capacity: " << towingCapacity << " tons" << std::endl;
}