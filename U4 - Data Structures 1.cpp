/*
// U4 - Data Structures 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// February 18, 2024

#include <iostream>
#include <string>

using namespace std;

// Structure for win/loss record
struct WinLoss {
    int wins;
    int losses;
};

// Structure for team information
struct Team {
    string teamName;
    WinLoss total;
    WinLoss home;
    WinLoss away;
};

// Function prototypes
int menu();
WinLoss getWinLoss(string location);
void displayWinLoss(WinLoss record);
Team getTeam();
void displayTeam(Team team);
void findTeam(Team teams[], int teamCount);

int main() {
    const int MAX_TEAMS = 10;
    Team teams[MAX_TEAMS];
    int teamCount = 0;

    int choice;

    do {
        // Display menu and get user choice
        choice = menu();

        // Perform the selected operation
        switch (choice) {
        case 1:
            // Enter a new team
            if (teamCount < MAX_TEAMS) {
                teams[teamCount] = getTeam();
                ++teamCount;
            }
            else {
                cout << "Maximum number of teams reached.\n";
            }
            break;
        case 2:
            // Display all teams
            for (int i = 0; i < teamCount; ++i) {
                displayTeam(teams[i]);
            }
            break;
        case 3:
            // Display a particular team
            findTeam(teams, teamCount);
            break;
        case 4:
            // Exit the program
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

// Function to display the menu and get user's selection
int menu() {
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Enter a new team\n";
    cout << "2. Display all teams\n";
    cout << "3. Display a particular team\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}

// Function to get wins and losses for a specific location
WinLoss getWinLoss(string location) {
    WinLoss record;
    cout << "Enter " << location << " wins: ";
    cin >> record.wins;
    cout << "Enter " << location << " losses: ";
    cin >> record.losses;
    return record;
}

// Function to display win/loss record
void displayWinLoss(WinLoss record) {
    cout << record.wins << "-" << record.losses;
}

// Function to get information for a new team
Team getTeam() {
    Team newTeam;
    cout << "Enter the team name: ";
    cin.ignore();
    getline(cin, newTeam.teamName);

    // Get home wins and losses
    newTeam.home = getWinLoss("home");

    // Get away wins and losses
    newTeam.away = getWinLoss("away");

    // Calculate total wins and losses
    newTeam.total.wins = newTeam.home.wins + newTeam.away.wins;
    newTeam.total.losses = newTeam.home.losses + newTeam.away.losses;

    return newTeam;
}

// Function to display team information
void displayTeam(Team team) {
    cout << "Team Name: " << team.teamName << "\n";
    cout << "Total Wins/Losses: ";
    displayWinLoss(team.total);
    cout << "\nHome Wins/Losses: ";
    displayWinLoss(team.home);
    cout << "\nAway Wins/Losses: ";
    displayWinLoss(team.away);
    cout << "\n\n";
}

// Function to find and display information for a particular team
void findTeam(Team teams[], int teamCount) {
    string searchName;
    cout << "Enter the team name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < teamCount; ++i) {
        if (teams[i].teamName == searchName) {
            displayTeam(teams[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Team not found.\n";
    }
}
*/