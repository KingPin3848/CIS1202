#pragma once
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car();
    Car(const std::string& manu, int year, int doors);
    void setNumDoors(int doors);
    int getNumDoors() const;
    void displayInfo() const override;
};

#endif