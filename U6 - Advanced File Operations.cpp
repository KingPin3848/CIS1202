#include <iostream>
#include <fstream>
#include <cstring>

struct Product {
    long number;
    char name[40];
    double price;
    int quantity;
};

int showMenu();
void createFile(std::fstream&);
void displayFile(std::fstream&);
void displayRecord(std::fstream&, int);
void modifyRecord(std::fstream&);

int main() {
    std::fstream inventoryFile("inventory.dat", std::ios::binary | std::ios::in | std::ios::out);

    if (!inventoryFile) {
        std::cout << "Error creating or opening the file.\n";
        return 1;
    }

    createFile(inventoryFile);

    char choice;
    do {
        choice = showMenu();

        switch (choice) {
        case 'a':
            displayFile(inventoryFile);
            break;
        case 'b': {
            int recordNumber;
            std::cout << "Enter the record number: ";
            std::cin >> recordNumber;
            displayRecord(inventoryFile, recordNumber);
            break;
        }
        case 'c':
            modifyRecord(inventoryFile);
            break;
        case 'd':
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 'd');

    inventoryFile.close();
    return 0;
}

int showMenu() {
    std::cout << "\nInventory Management Menu:\n";
    std::cout << "a. Display entire inventory\n";
    std::cout << "b. Display a particular product\n";
    std::cout << "c. Modify a product\n";
    std::cout << "d. Exit\n";
    std::cout << "Enter your choice: ";

    char choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the input buffer
    return choice;
}

void createFile(std::fstream& f) {
    Product p1 = { 1001, "Laptop", 899.99, 15 };
    Product p2 = { 1002, "Smartphone", 499.99, 20 };
    Product p3 = { 1003, "Headphones", 79.99, 30 };
    Product p4 = { 1004, "Camera", 599.99, 10 };
    Product p5 = { 1005, "Printer", 199.99, 12 };
    Product p6 = { 1006, "Tablet", 299.99, 18 };
    Product p7 = { 1007, "Monitor", 249.99, 25 };
    Product p8 = { 1008, "Keyboard", 49.99, 40 };
    Product p9 = { 1009, "Mouse", 29.99, 50 };
    Product p10 = { 1010, "External Hard Drive", 129.99, 8 };
    Product p11 = { 1011, "Speaker System", 149.99, 22 };
    Product p12 = { 1012, "Wireless Router", 89.99, 15 };
    Product p13 = { 1013, "Gaming Console", 299.99, 10 };
    Product p14 = { 1014, "Fitness Tracker", 79.99, 35 };
    Product p15 = { 1015, "Coffee Maker", 39.99, 28 };
    Product p16 = { 1016, "Vacuum Cleaner", 129.99, 14 };
    Product p17 = { 1017, "Power Drill", 79.99, 18 };
    Product p18 = { 1018, "Toaster", 24.99, 32 };
    Product p19 = { 1019, "Blender", 49.99, 20 };
    Product p20 = { 1020, "Digital Watch", 59.99, 25 };

    f.write(reinterpret_cast<char*>(&p1), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p2), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p3), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p4), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p5), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p6), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p7), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p8), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p9), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p10), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p11), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p12), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p13), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p14), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p15), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p16), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p17), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p18), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p19), sizeof(Product));
    f.write(reinterpret_cast<char*>(&p20), sizeof(Product));
}

void displayFile(std::fstream& f) {
    f.clear(); // clear the eof flag
    f.seekg(0, std::ios::beg); // seek to the beginning

    Product p;
    int recordNumber = 1;

    while (f.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        std::cout << "Record " << recordNumber << ":\n";
        std::cout << "Number: " << p.number << "\n";
        std::cout << "Name: " << p.name << "\n";
        std::cout << "Price: " << p.price << "\n";
        std::cout << "Quantity: " << p.quantity << "\n\n";
        ++recordNumber;
    }
}

void displayRecord(std::fstream& f, int recordNumber) {
    f.clear();
    f.seekg((recordNumber - 1) * sizeof(Product), std::ios::beg);

    Product p;
    if (f.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        std::cout << "Record " << recordNumber << ":\n";
        std::cout << "Number: " << p.number << "\n";
        std::cout << "Name: " << p.name << "\n";
        std::cout << "Price: " << p.price << "\n";
        std::cout << "Quantity: " << p.quantity << "\n\n";
    }
    else {
        std::cout << "Record not found.\n";
    }
}

void modifyRecord(std::fstream& f) {
    int recordNumber;
    std::cout << "Enter the record number to modify: ";
    std::cin >> recordNumber;

    f.clear();
    f.seekp((recordNumber - 1) * sizeof(Product), std::ios::beg);

    Product newProduct;
    std::cout << "Enter new product details:\n";
    std::cout << "Number: ";
    std::cin >> newProduct.number;
    std::cout << "Name: ";
    std::cin.ignore(); // clear the newline character from the buffer
    std::cin.getline(newProduct.name, 40);
    std::cout << "Price: ";
    std::cin >> newProduct.price;
    std::cout << "Quantity: ";
    std::cin >> newProduct.quantity;

    f.write(reinterpret_cast<char*>(&newProduct), sizeof(Product));

    std::cout << "Record " << recordNumber << " modified.\n";
}
