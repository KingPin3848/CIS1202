/*
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

// Function prototypes
bool valid(char[]);
void origin(char[], char[]);
int year(char[]);

int main() {
    // Buffer for user input
    char vin[18];

    // Prompt user for VIN input
    std::cout << "Enter the VIN: " << endl;
    cin >> vin;

    // Display information about the entered VIN
    if (valid(vin)) {
        char originStr[20];
        origin(vin, originStr);

        std::cout << "VIN is valid" << endl;
        std::cout << "Origin: " << originStr << std::endl;
        std::cout << "Year: " << year(vin) << endl;
    }
    else {
        std::cout << "VIN is not valid" << endl;
    }

    return 0;
}

// Function to check if VIN is valid
bool valid(char vin[]) {
    // Check if VIN length is 17
    if (strlen(vin) != 17) {
        return false;
    }

    // Check if VIN contains only uppercase letters and digits
    for (int i = 0; i < 17; ++i) {
        if (!isalnum(vin[i]) || vin[i] == 'I' || vin[i] == 'O' || vin[i] == 'Q' || vin[i] == 'U' || vin[i] == 'Z') {
            return false;
        }
    }

    return true;
}

// Function to determine origin from VIN
void origin(char vin[], char originStr[]) {
    char originCode = vin[0];

    // Determine origin based on the first character of VIN
    if (originCode >= 'A' && originCode <= 'H') {
        strcpy_s(originStr, 20, "Africa");
    }
    else if (originCode >= 'J' && originCode <= 'R') {
        strcpy_s(originStr, 20, "Asia");
    }
    else if (originCode >= 'S' && originCode <= 'Y') {
        strcpy_s(originStr, 20, "Europe");
    }
    else if (originCode >= '1' && originCode <= '5') {
        strcpy_s(originStr, 20, "North America");
    }
    else if (originCode == '6' || originCode == '7') {
        strcpy_s(originStr, 20, "Oceania");
    }
    else if (originCode >= '8' && originCode <= '0') {
        strcpy_s(originStr, 20, "South America");
    }
}

// Function to determine model year from VIN
int year(char vin[]) {
    char yearCode = vin[9];

    // Determine year based on the tenth character of VIN
    if (yearCode >= 'P' && yearCode <= 'Y') {
        return 1993 + (yearCode - 'P');
    }
    else if (yearCode >= '1' && yearCode <= '9') {
        return 2001 + (yearCode - '1');
    }
    else if (yearCode >= 'A' && yearCode <= 'M') {
        return 2010 + (yearCode - 'A');
    }

    return -1; // Return -1 for invalid year code
}
*/