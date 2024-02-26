/*
// U2 - SearchingSortingArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// January 16, 2024

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void loadArrays(string[], float[], int&);
void showArrays(string[], float[], int);
void lookUpPrice(string[], float[], int);
void sortPrices(string[], float[], int);
void highestPrice(string[], float[], int);
int showMenu();

int main() {
    // Maximum number of consoles
    const int MAX_CONSOLES = 100;

    // Arrays to store console names and prices
    string console[MAX_CONSOLES];
    float price[MAX_CONSOLES];

    // Variable to track the number of consoles
    int numConsoles = 0;

    // Load data from the file
    loadArrays(console, price, numConsoles);

    // Menu-driven program
    int choice;
    do {
        choice = showMenu();

        switch (choice) {
        case 1:
            showArrays(console, price, numConsoles);
            break;
        case 2:
            lookUpPrice(console, price, numConsoles);
            break;
        case 3:
            sortPrices(console, price, numConsoles);
            break;
        case 4:
            highestPrice(console, price, numConsoles);
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void loadArrays(string console[], float price[], int& numConsoles) {
    ifstream file("prices.txt");

    if (!file) {
        cerr << "Error opening file.\n";
        exit(1);
    }

    int i = 0;
    while (getline(file, console[i])) {
        string temp;
        getline(file, temp);
        price[i] = stof(temp);
        i++;
    }

    numConsoles = i;

    file.close();
}

void showArrays(string console[], float price[], int numConsoles) {
    cout << setw(30) << left << "Console" << setw(10) << right << "Price" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    for (int i = 0; i < numConsoles; i++) {
        cout << setw(30) << left << console[i] << "$" << setw(9) << fixed << setprecision(2) << right << price[i] << endl;
    }

    cout << endl;
}

void lookUpPrice(string console[], float price[], int numConsoles) {
    string targetConsole;
    cout << "Enter the name of the console to look up: ";
    getline(cin, targetConsole);

    bool found = false;
    for (int i = 0; i < numConsoles; i++) {
        if (console[i] == targetConsole) {
            cout << "The price of " << targetConsole << " is $" << fixed << setprecision(2) << price[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Console not found.\n";
    }

    cout << endl;
}

void sortPrices(string console[], float price[], int numConsoles) {
    for (int i = 0; i < numConsoles - 1; i++) {
        for (int j = 0; j < numConsoles - i - 1; j++) {
            if (price[j] < price[j + 1]) {
                // Swap prices
                float tempPrice = price[j];
                price[j] = price[j + 1];
                price[j + 1] = tempPrice;

                // Swap console names
                string tempConsole = console[j];
                console[j] = console[j + 1];
                console[j + 1] = tempConsole;
            }
        }
    }

    cout << "Prices sorted in descending order.\n\n";
}

void highestPrice(string console[], float price[], int numConsoles) {
    float maxPrice = price[0];
    int index = 0;

    for (int i = 1; i < numConsoles; i++) {
        if (price[i] > maxPrice) {
            maxPrice = price[i];
            index = i;
        }
    }

    cout << "The console with the highest price is " << console[index] << " with a price of $" << fixed << setprecision(2) << maxPrice << endl << endl;
}

int showMenu() {
    cout << "Menu:\n";
    cout << "1. Display all console prices\n";
    cout << "2. Look up the price of a particular console\n";
    cout << "3. Sort prices in descending order\n";
    cout << "4. Display the console with the highest price\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";

    int choice;
    cin >> choice;
    cin.ignore();  // Consume the newline character

    return choice;
}
*/