#pragma once
// Publication.h
#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>

enum PublicationType { BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO };

class Publication {
private:
    std::string title;
    std::string publisher;
    double price;
    int year;
    PublicationType type;
    int stock;

public:
    // Constructors
    Publication();
    Publication(std::string itemTitle, std::string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock);

    // Member functions
    void storePublication(std::string itemTitle, std::string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock);
    void displayInfo();
    void checkOut();
    void checkIn();
    std::string getTitle();
    int getStock();
};

#endif // PUBLICATION_H
