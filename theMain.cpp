/*
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <iostream>
#include <string>

int main() {
    // Vehicle
    std::string manufacturer;
    int yearBuilt;

    std::cout << "Enter manufacturer for Vehicle: ";
    std::getline(std::cin, manufacturer);

    std::cout << "Enter year built for Vehicle: ";
    std::cin >> yearBuilt;

    Vehicle vehicle(manufacturer, yearBuilt);
    vehicle.displayInfo();

    // Car
    std::cin.ignore(); // Clear newline from previous input
    std::cout << "\nCar: ";
    std::cout << "\nEnter manufacturer for Car: ";
    std::getline(std::cin, manufacturer);

    std::cout << "Enter year built for Car: ";
    std::cin >> yearBuilt;

    int numDoors;
    std::cout << "Enter number of doors for Car: ";
    std::cin >> numDoors;

    Car car(manufacturer, yearBuilt, numDoors);
    car.displayInfo();

    // Truck
    std::cin.ignore(); // Clear newline from previous input
    std::cout << "\nTruck: ";
    std::cout << "\nEnter manufacturer for Truck: ";
    std::getline(std::cin, manufacturer);

    std::cout << "Enter year built for Truck: ";
    std::cin >> yearBuilt;

    double towingCapacity;
    std::cout << "Enter towing capacity for Truck (in tons): ";
    std::cin >> towingCapacity;

    Truck truck(manufacturer, yearBuilt, towingCapacity);
    truck.displayInfo();

    return 0;
}
*/