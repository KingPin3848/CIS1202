/*
// Midterm-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// February 22, 2024
#include <iostream>
#include <cstring>

struct ExerciseLog {
    char activityName[50];
    float duration; // in minutes
    float caloriesBurned;
};

struct DailyLog {
    char date[15];
    ExerciseLog exercise;
    char meal[50];
};

void static inputLog(DailyLog& log) {
    std::cout << "Enter date (MM/DD/YYYY): ";
    std::cin >> log.date;

    std::cout << "Enter exercise details:\n";
    std::cout << "Activity name: ";
    std::cin.ignore(); // clear the newline character from the buffer
    std::cin.getline(log.exercise.activityName, 50);

    std::cout << "Duration (minutes): ";
    std::cin >> log.exercise.duration;

    std::cout << "Calories burned: ";
    std::cin >> log.exercise.caloriesBurned;

    std::cout << "Enter meal details: ";
    std::cin.ignore(); // clear the newline character from the buffer
    std::cin.getline(log.meal, 50);
}

void static displayLogs(const DailyLog logs[], int count) {
    std::cout << "\nDate\t\tActivity\tDuration\tCalories\tMeal\n";
    for (int i = 0; i < count; ++i) {
        std::cout << logs[i].date << "\t"
            << logs[i].exercise.activityName << "\t"
            << logs[i].exercise.duration << "\t\t"
            << logs[i].exercise.caloriesBurned << "\t\t"
            << logs[i].meal << "\n";
    }
}

void static sortByDate(DailyLog logs[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (strcmp(logs[j].date, logs[j + 1].date) > 0) {
                // Swap logs[j] and logs[j+1]
                DailyLog temp = logs[j];
                logs[j] = logs[j + 1];
                logs[j + 1] = temp;
            }
        }
    }
}

void static searchLogs(const DailyLog logs[], int count, const char query[]) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strstr(logs[i].exercise.activityName, query) != nullptr ||
            strstr(logs[i].meal, query) != nullptr) {
            // Display log if the query is found in activity name or meal
            std::cout << logs[i].date << "\t"
                << logs[i].exercise.activityName << "\t"
                << logs[i].exercise.duration << "\t\t"
                << logs[i].exercise.caloriesBurned << "\t\t"
                << logs[i].meal << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching logs found.\n";
    }
}

int main() {
    DailyLog logs[100];
    int logCount = 0;

    char choice;
    do {
        std::cout << "\nFitness Tracker Menu:\n";
        std::cout << "1. Log Exercise\n";
        std::cout << "2. Display Logs\n";
        std::cout << "3. Sort Logs by Date\n";
        std::cout << "4. Search Logs\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            if (logCount < 100) {
                inputLog(logs[logCount]);
                ++logCount;
            }
            else {
                std::cout << "Log limit reached.\n";
            }
            break;
        case '2':
            displayLogs(logs, logCount);
            break;
        case '3':
            sortByDate(logs, logCount);
            std::cout << "Logs sorted by date.\n";
            break;
        case '4': {
            char query[50];
            std::cout << "Enter search query: ";
            std::cin.ignore();
            std::cin.getline(query, 50);
            searchLogs(logs, logCount, query);
            break;
        }
        case '5':
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '5');

    return 0;
}
*/