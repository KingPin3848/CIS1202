/*
// Unit-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// January 12, 2024

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 20;

// Function prototypes
void loadArrays(string[], int[], float[], int&);
void calculateValues(int[], float[], float[], int);
void displayTable(string[], int[], float[], float[], int);

int main() {
    // Declare arrays
    string product[SIZE];
    int quantity[SIZE];
    float cost[SIZE];
    float value[SIZE];

    // Variable to store the number of items read from the file
    int itemCount = 0;

    // Step 1: Read input file
    loadArrays(product, quantity, cost, itemCount);

    // Step 2: Calculate values
    calculateValues(quantity, cost, value, itemCount);

    // Step 3: Display table
    displayTable(product, quantity, cost, value, itemCount);

    return 0;
}

// Function to read input file into arrays and return the count
void loadArrays(string product[], int quantity[], float cost[], int& itemCount) {
    ifstream inputFile("inventory.txt");

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        exit(1);
    }

    // Read data into arrays
    while (itemCount < SIZE && inputFile >> product[itemCount] >> quantity[itemCount] >> cost[itemCount]) {
        itemCount++;
    }

    // Close the file
    inputFile.close();
}

// Function to calculate values based on quantity and cost
void calculateValues(int quantity[], float cost[], float value[], int itemCount) {
    for (int i = 0; i < itemCount; i++) {
        value[i] = quantity[i] * cost[i];
    }
}

// Function to display the table with formatted output
void displayTable(string product[], int quantity[], float cost[], float value[], int itemCount) {
    float totalValue = 0;
    float highestValue = value[0];
    int highestValueIndex = 0;

    cout << setw(15) << "Product Code" << setw(15) << "Quantity" << setw(15) << "Cost Each" << setw(15) << "Total Value" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (int i = 0; i < itemCount; i++) {
        cout << setw(15) << product[i] << setw(15) << quantity[i] << setw(15) << fixed << setprecision(2) << cost[i]
            << setw(15) << fixed << setprecision(2) << value[i];

        if (value[i] > 9000) {
            cout << " *";  // Indicator for total value over $9,000
        }

        cout << endl;

        totalValue += value[i];

        if (value[i] > highestValue) {
            highestValue = value[i];
            highestValueIndex = i;
        }
    }

    cout << "\nProduct with the highest total value: " << product[highestValueIndex] << " ($" << highestValue << ")\n";
    cout << "Average value of an inventory item: $" << totalValue / itemCount << endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/