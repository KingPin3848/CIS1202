/*
// U3 - Pointers2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// January 30, 2024

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
int getMenuItem();
void enterRents(float*, int);
void displayRents(float*, int);
float sumRents(float*, int);
void displayMemoryLocations(float*, int);
void selectionSort(float*, int);

int main() {
    const int MAX_PROPERTIES = 7;
    float rents[MAX_PROPERTIES];

    int choice;

    do {
        // Display menu and get user choice
        choice = getMenuItem();

        // Perform the selected operation
        switch (choice) {
        case 1:
            enterRents(rents, MAX_PROPERTIES);
            break;
        case 2:
            displayRents(rents, MAX_PROPERTIES);
            break;
        case 3:
            selectionSort(rents, MAX_PROPERTIES);
            cout << "Rent amounts sorted in ascending order.\n";
            break;
        case 4:
            cout << fixed << setprecision(2) << "Total rent amount: $" << sumRents(rents, MAX_PROPERTIES) << "\n";
            break;
        case 5:
            displayMemoryLocations(rents, MAX_PROPERTIES);
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

// Function to display the menu and get user's selection
int getMenuItem() {
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Enter rent amounts\n";
    cout << "2. Display rents\n";
    cout << "3. Sort rent amounts, low to high\n";
    cout << "4. Calculate total rents\n";
    cout << "5. Display memory locations\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

// Function to enter rent amounts into an array, using pointers
void enterRents(float* rents, int numProperties) {
    cout << "Enter the rent amounts for the properties:\n";
    for (int i = 0; i < numProperties; ++i) {
        cout << "Property " << (i + 1) << ": ";
        cin >> *(rents + i);
    }
}

// Function to display rent amounts using pointers
void displayRents(float* rents, int numProperties) {
    cout << "Rent amounts:\n";
    for (int i = 0; i < numProperties; ++i) {
        cout << fixed << setprecision(2) << "$" << *(rents + i) << "\n";
    }
}

// Function to calculate total rent amounts using pointers
float sumRents(float* rents, int numProperties) {
    float total = 0;
    for (int i = 0; i < numProperties; ++i) {
        total += *(rents + i);
    }
    return total;
}

// Function to display memory locations of array elements, using pointers
void displayMemoryLocations(float* rents, int numProperties) {
    cout << "Memory locations of array elements:\n";
    for (int i = 0; i < numProperties; ++i) {
        cout << "&rents[" << i << "]: " << (rents + i) << "\n";
    }
}

// Function to sort rent amounts using selection sort, using pointers
void selectionSort(float* rents, int numProperties) {
    for (int i = 0; i < numProperties - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < numProperties; ++j) {
            if (*(rents + j) < *(rents + minIndex)) {
                minIndex = j;
            }
        }
        // Swap
        float temp = *(rents + i);
        *(rents + i) = *(rents + minIndex);
        *(rents + minIndex) = temp;
    }
}
*/