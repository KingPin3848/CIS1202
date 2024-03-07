// Publication.cpp
#include "Publication.h"
#include <iostream>

// Constructors
Publication::Publication() {
    title = "";
    publisher = "";
    price = 0.0;
    year = 0;
    type = BOOK;
    stock = 0;
}

Publication::Publication(std::string itemTitle, std::string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    storePublication(itemTitle, itemPublisher, itemPrice, itemYear, itemType, itemStock);
}

// Member functions
void Publication::storePublication(std::string itemTitle, std::string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

void Publication::displayInfo() {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Stock: " << stock << " copies" << std::endl;
}

void Publication::checkOut() {
    if (stock > 0) {
        stock--;
        std::cout << "Checked out successfully." << std::endl;
    }
    else {
        std::cout << "Publication out of stock." << std::endl;
    }
}

void Publication::checkIn() {
    stock++;
    std::cout << "Checked in successfully." << std::endl;
}

std::string Publication::getTitle() {
    return title;
}

int Publication::getStock() {
    return stock;
}
