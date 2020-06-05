// Scott Tornquist
// Computer Science 1 
// Assignment #2
// 11/14/19

#include <iostream>
#include <vector>
#include <cstdlib>

/*
Example output:
My deck: 2 1 2 2 4 
Your deck: 2 4 0 4 1 
I won a war

My deck: 2 2 4 2 2 4 1 
Your deck: 0 4 1 
I won the card

My deck: 2 4 2 2 4 1 2 0 
Your deck: 4 1 
You won the card

My deck: 4 2 2 4 1 2 0 
Your deck: 1 2 4 
I won the card

My deck: 2 2 4 1 2 0 4 1 
Your deck: 2 4 
I won a war

I win!*/

using namespace std;

// Given a vector, remove and return the first element
int removeCard(vector<int> &deck);

// Create a new vector containing card values.  The vector should contain
// the specified number of elements, and each element should be a random
// integer between 0 and maxNumber-1 (inclusive).
vector<int> createDeck(int numCards, int maxNumber);

// Displays the deck to the screen.  Elements should be output separated
// by spaces, and a newline should be output at the end.
void displayDeck(vector<int> deck);

int main() {
    srand(time(0));
    cout<<endl;
    // Number of cards in each deck
    const int NUM_CARDS = 5;

    // Maximum card value
    const int MAX_NUMBER = 5;

    // myDeck represents my deck
    vector<int> myDeck = createDeck(NUM_CARDS, MAX_NUMBER);
    // and yourDeck represents your deck
    vector<int> yourDeck = createDeck(NUM_CARDS, MAX_NUMBER);

    // Keeps track of the number of moves to avoid an infinite loop
    int moves = 0;

    while ( (myDeck.size()>0) && (yourDeck.size()>0) &&(moves++ < 1000)) {
        cout << "\nMy deck: ";
        displayDeck(myDeck);
        cout << "\nYour deck: ";
        displayDeck(yourDeck);
        int myCard = removeCard(myDeck);
        int yourCard = removeCard(yourDeck);

        cout <<endl;
        cout << yourCard<<endl;

        if(myCard> yourCard){
            myDeck.push_back(myCard);
            myDeck.push_back(yourCard);
            cout<< "I won the Card!"<<endl;
        }
        else if(myCard < yourCard){
            yourDeck.push_back(myCard);
            yourDeck.push_back(yourCard);
            cout<< "You won the Card!"<<endl;
        }
        else {
            if ((rand()%10)<5){
                   myDeck.push_back(myCard);
                    myDeck.push_back(yourCard);
                    cout<< "I won the Card!"<<endl;
                }
            else{ 
                yourDeck.push_back(myCard);
                yourDeck.push_back(yourCard);
                cout<< "You won the Card!"<<endl;
            }
        }

        
        // Take the two cards and see which one is larger.  Whichever player has
        // the largest value wins both of the cards and has both of them added
        // to the end of their deck.
        //
        // If both players play the same card, each player takes an additional
        // card from their deck.  A coin is flipped to determine which player
        // wins _all_four_ of the cards.  The cards are added to the end of
        // the winning player's deck.
        // 
        // In the case that a player tries to remove a card from their deck but
        // their deck is empty, they lose.
        //
        // When you add cards to a deck, it doesn't matter which order you add
        // the two (or four) cards.
        cout << endl;
    }
    if (myDeck.size() == 0) {
        cout << "You win!" << endl;
    } else if (yourDeck.size() == 0) {
        cout << "I win!" << endl;
    } else {
        cout << "Call it a draw." << endl;
    }
}

int removeCard(vector<int> &deck) {
    int answer = deck[0];

    // Erase the first element of the array, shifting all other elements
    // down by one.
    deck.erase(deck.begin());
    return answer;
}
vector<int> createDeck(int numCards, int maxNumber) {
    vector<int> victor ={1,2,3,4,5};
    for (int i=0; i<= numCards; i++){
        victor[i] = ((rand()%maxNumber)+1);
    }
    return victor;
}

void displayDeck(vector<int> deck) {
    for (int i=0; i<deck.size(); i++){
        cout << deck.at(i)<< " ";
    }
}
