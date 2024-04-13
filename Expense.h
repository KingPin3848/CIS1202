#pragma once
#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

// Base class
class Expense {
protected:
    std::string name;
    double amount;
public:
    // Constructor
    Expense(std::string n, double a) : name(n), amount(a) {}

    // Accessor functions
    std::string getName() const { return name; }
    double getAmount() const { return amount; }

    // Mutator functions
    void setName(std::string n) { name = n; }
    void setAmount(double a) { amount = a; }

    // Display function
    virtual void display() const {
        std::cout << "Expense: " << name << ", Amount: " << amount << std::endl;
    }
};

// Derived class
class MonthlyExpense : public Expense {
private:
    int month;
public:
    // Constructor
    MonthlyExpense(std::string n, double a, int m) : Expense(n, a), month(m) {}

    // Accessor function
    int getMonth() const { return month; }

    // Mutator function
    void setMonth(int m) { month = m; }

    // Overloaded display function
    void display() const override {
        std::cout << "Expense: " << name << ", Amount: " << amount << ", Month: " << month << std::endl;
    }
};

#endif