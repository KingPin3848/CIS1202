#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string manufacturer;
    int yearBuilt;

public:
    Vehicle();
    Vehicle(const std::string& manu, int year);
    void setManufacturer(const std::string& manu);
    std::string getManufacturer() const;
    void setYearBuilt(int year);
    int getYearBuilt() const;
    void virtual displayInfo() const;
};

#endif