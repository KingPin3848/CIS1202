// Main.cpp
#include "Publication.h"
#include <iostream>

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

int main() {
    Publication publication;

    // Call getPublicationInfo to store in a Publication variable
    getPublicationInfo(publication);

    // Call getTitle and display the title
    std::cout << "Title: " << publication.getTitle() << std::endl;

    // Call checkOut
    publication.checkOut();

    // Call getStock and display the number of copies in stock
    std::cout << "Stock: " << publication.getStock() << " copies" << std::endl;

    // Call checkIn
    publication.checkIn();

    // Call getStock and display the number of copies in stock
    std::cout << "Stock: " << publication.getStock() << " copies" << std::endl;

    return 0;
}
