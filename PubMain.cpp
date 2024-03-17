/*
// PubMain.cpp
#include "Publication.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void getPublicationInfo(Publication& pub) {
    std::string title, publisher;
    double price;
    int year, stock;
    PublicationType type;

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    std::cout << "Enter publisher: ";
    std::getline(std::cin, publisher);

    std::cout << "Enter price: ";
    std::cin >> price;

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cout << "Enter type (0-Book, 1-Magazine, 2-Newspaper, 3-Audio, 4-Video): ";
    int typeInt;
    std::cin >> typeInt;
    type = static_cast<PublicationType>(typeInt);

    std::cout << "Enter stock: ";
    std::cin >> stock;

    pub.storePublication(title, publisher, price, year, type, stock);
}

void getPublications(Publication list[], int& size) {
    std::ifstream file("U7Data.txt");
    if (!file) {
        std::cerr << "Unable to open file";
        exit(1); // terminate with error
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string title = line;
        std::getline(file, line);
        std::string publisher = line;
        std::getline(file, line);
        double price = std::stod(line);
        std::getline(file, line);
        int year = std::stoi(line);
        std::getline(file, line);
        PublicationType type = static_cast<PublicationType>(std::stoi(line));
        std::getline(file, line);
        int stock = std::stoi(line);

        list[size++] = Publication(title, publisher, price, year, type, stock);
    }

    file.close();
}

void showPublications(Publication list[], int size) {
    for (int i = 0; i < size; ++i) {
        list[i].displayInfo();
    }
}

void showTitles(Publication list[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << list[i].getTitle() << std::endl;
    }
}

int findPublication(Publication list[], int size, std::string targetTitle) {
    for (int i = 0; i < size; ++i) {
        if (list[i].getTitle() == targetTitle) {
            return i;
        }
    }
    return -1; // Sentinel indicating not found
}

int getMenuChoice() {
    int choice;
    std::cout << "\nMenu:\n";
    std::cout << "1. Display all publications\n";
    std::cout << "2. Display publication titles\n";
    std::cout << "3. Find a publication\n";
    std::cout << "4. Check out\n";
    std::cout << "5. Check in\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int main() {
    const int MAX_PUBLICATIONS = 100;
    Publication publications[MAX_PUBLICATIONS];
    int numPublications = 0;

    getPublications(publications, numPublications);

    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            showPublications(publications, numPublications);
            break;
        case 2:
            showTitles(publications, numPublications);
            break;
        case 3: {
            std::cin.ignore(); // Clear newline from previous input
            std::string targetTitle;
            std::cout << "Enter the title to find: ";
            std::getline(std::cin, targetTitle);
            int foundIndex = findPublication(publications, numPublications, targetTitle);
            if (foundIndex != -1) {
                publications[foundIndex].displayInfo();
            }
            else {
                std::cout << "Publication not found." << std::endl;
            }
            break;
        }
        case 4: {
            std::cin.ignore(); // Clear newline from previous input
            std::string targetTitle;
            std::cout << "Enter the title to check out: ";
            std::getline(std::cin, targetTitle);
            int foundIndex = findPublication(publications, numPublications, targetTitle);
            if (foundIndex != -1) {
                publications[foundIndex].checkOut();
            }
            else {
                std::cout << "Publication not found." << std::endl;
            }
            break;
        }
        case 5: {
            std::cin.ignore(); // Clear newline from previous input
            std::string targetTitle;
            std::cout << "Enter the title to check in: ";
            std::getline(std::cin, targetTitle);
            int foundIndex = findPublication(publications, numPublications, targetTitle);
            if (foundIndex != -1) {
                publications[foundIndex].checkIn();
            }
            else {
                std::cout << "Publication not found." << std::endl;
            }
            break;
        }
        case 6:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 6);

    return 0;
}
*/