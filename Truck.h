#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double towingCapacity;

public:
    Truck();
    Truck(const std::string& manu, int year, double capacity);
    void setTowingCapacity(double capacity);
    double getTowingCapacity() const;
    void displayInfo() const override;
};

#endif