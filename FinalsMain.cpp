#include <iostream>
#include <fstream>
#include <vector>
#include "Expense.h"

static void writeExpenses(const std::vector<MonthlyExpense>& expenses, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    for (const auto& expense : expenses) {
        // Write the size of the name
        size_t size = expense.getName().size();
        outFile.write((char*)&size, sizeof(size));
        // Write the name
        outFile.write(expense.getName().c_str(), size);
        // Write the amount
        double amount = expense.getAmount();
        outFile.write((char*)&amount, sizeof(amount));
        // Write the month
        int month = expense.getMonth();
        outFile.write((char*)&month, sizeof(month));
    }
    outFile.close();
}

static void readExpenses(std::vector<MonthlyExpense>& expenses, const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    while (inFile.peek() != EOF) {
        // Read the size of the name
        size_t size;
        inFile.read((char*)&size, sizeof(size));
        // Read the name
        std::string name(size, ' ');
        inFile.read(&name[0], size);
        // Read the amount
        double amount;
        inFile.read((char*)&amount, sizeof(amount));
        // Read the month
        int month;
        inFile.read((char*)&month, sizeof(month));
        // Add the expense to the vector
        expenses.push_back(MonthlyExpense(name, amount, month));
    }
    inFile.close();
}

static void addExpense(std::vector<MonthlyExpense>& expenses) {
    std::string name;
    double amount;
    int month;

    std::cout << "Enter expense name: ";
    std::cin >> name;
    std::cin.clear();

    std::cout << "Enter expense amount: ";
    std::cin >> amount;
    while (std::cin.fail() || amount < 0) {
        std::cout << "Invalid input. Please enter a positive number for the amount: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> amount;
    }

    std::cout << "Enter expense month (1-12): ";
    std::cin >> month;
    while (std::cin.fail() || month < 1 || month > 12) {
        std::cout << "Invalid input. Please enter a number between 1 and 12 for the month: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> month;
    }

    expenses.push_back(MonthlyExpense(name, amount, month));
}

static void showExpenses(const std::vector<MonthlyExpense>& expenses) {
    for (const auto& expense : expenses) {
        expense.display();
    }
}

static void findExpense(const std::vector<MonthlyExpense>& expenses) {
    std::string name;
    std::cout << "Enter the name of the expense you want to find: ";
    std::cin >> name;

    bool found = false;
    for (const auto& expense : expenses) {
        if (expense.getName() == name) {
            expense.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Expense not found.\n";
    }
}

int main() {
    std::vector<MonthlyExpense> expenses;

    // Read from binary file
    std::ifstream inFile("expenses.dat", std::ios::binary);
    MonthlyExpense expense("", 0, 0);
    readExpenses(expenses, "expenses.dat");

    // User instructions
    std::cout << "Enter 1 to add an expense, 2 to show all expenses, 3 to find an expense, or 4 to quit.\n";

    int choice;
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cin.clear();
            addExpense(expenses);
            break;
        }
        case 2: {
            std::cin.clear();
            showExpenses(expenses);
            break;
        }
        case 3: {
            std::cin.clear();
            findExpense(expenses);
            break;
        }
        case 4: {
            std::cin.clear();
            // Write to binary file
            writeExpenses(expenses, "expenses.dat");
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";            
            break;
        }
    }

    return 0;
}