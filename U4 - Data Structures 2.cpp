/*
// U4 - Data Structures 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Shivam Vyas
// CIS-1202 800
// February 19, 2024

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Enumerated types for suits and ranks
enum suits { HEARTS, DIAMONDS, SPADES, CLUBS };
enum ranks { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

// Struct to represent a card
struct cards {
    suits suit;
    ranks rank;
};

// Function prototypes
void createDeck(cards[]);
void printDeck(cards[]);
string cardName(cards);
cards deal(cards[]);
string winner(cards, cards);

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));

    // Array of cards representing the deck
    cards deck[52];

    // Individual cards for dealing
    cards card1, card2;

    // Create and print the deck
    createDeck(deck);
    cout << "Deck:\n";
    printDeck(deck);

    // Deal card 1 and display
    card1 = deal(deck);
    cout << "Card 1: " << cardName(card1) << endl;

    // Deal card 2 and display
    card2 = deal(deck);
    cout << "Card 2: " << cardName(card2) << endl;

    // Display the winning card
    cout << "Winner: " << winner(card1, card2) << endl;

    return 0;
}

// Function to create a deck of cards
void createDeck(cards deck[]) {
    int index = 0;
    for (int s = HEARTS; s <= CLUBS; ++s) {
        for (int r = TWO; r <= ACE; ++r) {
            deck[index].suit = static_cast<suits>(s);
            deck[index].rank = static_cast<ranks>(r);
            ++index;
        }
    }
}

// Function to print the entire deck
void printDeck(cards deck[]) {
    for (int i = 0; i < 52; ++i) {
        cout << cardName(deck[i]) << "\n";
    }
}

// Function to convert card to string representation
string cardName(cards card) {
    string suitNames[] = { "Hearts", "Diamonds", "Spades", "Clubs" };
    string rankNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

    return rankNames[card.rank] + " of " + suitNames[card.suit];
}

// Function to deal a random card from the deck
cards deal(cards deck[]) {
    int index = rand() % 52;
    cards dealtCard = deck[index];

    // Remove the dealt card by replacing it with the last card in the deck
    deck[index] = deck[51];
    return dealtCard;
}

// Function to determine the winner between two cards
string winner(cards card1, cards card2) {
    string rankNames[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

    // Compare ranks (ignoring suits)
    if (card1.rank > card2.rank) {
        return cardName(card1) + " wins!";
    }
    else if (card1.rank < card2.rank) {
        return cardName(card2) + " wins!";
    }
    else {
        return "It's a tie!";
    }
}
*/