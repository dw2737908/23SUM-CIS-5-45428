/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Daniel Wallander
 *
 * Created on July 26, 2023, 7:59 PM
 */

#include <iostream> //Input and Output
#include <string> //Adds the string variable
#include <cctype> //Adds toupper()
#include <fstream> //Can read external files
#include <map> //Maps the ASCII Art
#include <cstdlib> //Random Number Generator
#include <array> //Adds Arrays
#include <vector> //Adds Vectors

using namespace std; //Standard Namespace
//Function that reads and close an external file every time it is called.
map<int, string> readCardArt(const string& filename, const string& CardInput) {
    ifstream inputFile(filename);
    map<int, string> CardArt;
    string line;

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return CardArt; // Return an empty map in case of an error.
    }
    int linesCounter = 0;
    bool characterFound = false;

    while (getline(inputFile, line)) {
        if (!characterFound && line.find(CardInput) != string::npos) {
            characterFound = true;
            continue; // Skip the line containing the character
        }
        if (characterFound && linesCounter < 6) {
            CardArt[linesCounter] = line;
            linesCounter++;
        }
        if (linesCounter == 6) {
            break; // Stop reading after six lines following the character
        }
    }
    inputFile.close();
    return CardArt;
}
//Main Function
int main(int argc, char** argv) {
    //Define Variables
    string CardInput;
    string line;
    char Choice;
    int Players;
    int Points;
    int Dealer = 0;
    int Player1 = 0;
    int Player2 = 0;
    int Player3 = 0;
    int Player4 = 0;
    int Largest = 0;
    //Determines how many players are going to play (Plus the dealer).
    cout << "How many players are playing? (Maximum: 4) ";
    cin >> Players;
    if (Players > 4 || Players < 1) {
        cout << "INVALID INPUT!";
        return 0;
    }
    //Random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    //Card Deck.
    array<string, 52> cardNumbers = { //Each card in the deck is assigned a number to 'shuffle' the deck easier.
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
        "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
        "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
        "51", "52"
    };
    const int numCards = cardNumbers.size();
    int randomIndex = std::rand() % numCards;
    //The Dealer goes first.
    cout << "Dealer's Cards" << endl;
    for (Dealer = 0; Dealer < 17; Dealer += Points) {//Dealer always hits if card total is under 17.
        int randomIndex = rand() % numCards;//Shuffles deck.
        CardInput = cardNumbers[randomIndex];//Chooses card.
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;//Draws chosen card.
            }
            //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {//A Diamond, A Heart, A Club, A Spade.
         if (Dealer >= 11) {
             Points = 1;
         }else {
             Points = 11;
         }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {//2 Diamond, 2 Heart, 2 Club, 2 Spade.
         Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {//3 Diamond, 3 Heart, 3 Club, 3 Spade.
         Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {//4 Diamond, 4 Heart, 4 Club, 4 Spade.
         Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {//5 Diamond, 5 Heart, 5 Club, 5 Spade.
         Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {//6 Diamond, 6 Heart, 6 Club, 6 Spade.
         Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {//7 Diamond, 7 Heart, 7 Club, 7 Spade.
         Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {//8 Diamond, 8 Heart, 8 Club, 8 Spade.
         Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {//9 Diamond, 9 Heart, 9 Club, 9 Spade.
         Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {//10 Diamond, 10 Heart, 10 Club, 10 Spade.
         Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {//J Diamond, J Heart, J Club, J Spade.
         Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {//Q Diamond, Q Heart, Q Club, Q Spade.
         Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {//K Diamond, K Heart, K Club, K Spade.
         Points = 10;
     }
        } else {//Debugging message. The players should never see this.
             cout << "ERROR! If you see this message, the developer messed up." << endl;
         }
     }
    //This checks to see how many players the user wants.
     if (Players == 1 || Players == 2 || Players == 3 || Players == 4) {        
        //Player1's turn
     cout << "Player1 Cards" << endl;
     for (int i = 0; i < 2; ++i) {
        int randomIndex = rand() % numCards;//Shuffles deck.
        CardInput = cardNumbers[randomIndex];//Chooses card.
         map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
         
         if (!cardArtMap.empty()) {
             
             for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;//Draws card.
             }
        } else {
            cout << "ERROR! If you see this message, the developer messed up." << endl;
        }

        //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player1 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
        Player1 += Points;//Adds card number to total and draws a second card.
     }
     cout << "Dealer's points: " << Dealer << endl;
     cout << "Player1 points: " << Player1 << endl;
     
     map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
     do {
        randomIndex = rand() % numCards;//Shuffles deck
         CardInput = cardNumbers[randomIndex];
         cardArtMap = readCardArt("card_art.txt", CardInput);        
        //The player makes his/her move.
         cout << "What would you like to do, Player 1? ((S)tand or (H)it)" << endl;
         cin >> Choice;
        Choice = toupper(Choice);//Input accepts both uppercase and lowercase.
        if (Choice == 'H'){//Hit draws a card.
     if (!cardArtMap.empty()) {
         cout << endl;
         for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;//Draws card.
         }
    } else {
        cout << "ERROR! If you see this message, the developer messed up." << endl;
    }
    //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player1 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
    Player1 += Points;//Adds card to total.
     cout << "Dealer's Points: " << Dealer << endl;
     cout << "Player1 Points: " << Player1 << endl;
         }
  } while (Choice != 'S');//If player chooses 'stand', their turn ends.
   
   }
  //Player 2 starts their turn.
    if (Players == 2 || Players == 3 || Players == 4) {//Checks to see if player2 was invited.
         
   cout << "Player2 Cards" << endl;
    for (int i = 0; i < 2; ++i) {//Draws 2 cards
        int randomIndex = rand() % numCards;//Shuffles deck.
         CardInput = cardNumbers[randomIndex];
         map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
         
         if (!cardArtMap.empty()) {
             
             for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;//Draws card.
             }
        } else {
            cout << "ERROR! If you see this message, the developer messed up." << endl;
        }

        //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player2 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
        Player2 += Points;//Adds card total.
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 points: " << Player1 << endl;
    cout << "Player2 points: " << Player2 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;//Shuffles deck.
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        //Player 2 makes a choice.
        cout << "What would you like to do Player 2? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;//Draws card.
        }
    } else {
        cout << "ERROR! If you see this message, the developer messed up." << endl;
    }
    //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player2 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
    Player2 += Points;//Adds card total.
     cout << "Dealer's Points: " << Dealer << endl;
     cout << "Player1 Points: " << Player1 << endl;
     cout << "Player2 Points: " << Player2 << endl;
         }
  } while (Choice != 'S');//Ends turn.
   
   }
    if (Players == 3 || Players == 4) {//Checks if the player was invited.
         
   cout << "Player3 Cards" << endl;
     for (int i = 0; i < 2; ++i) {
        int randomIndex = rand() % numCards;//Shuffles deck.
         CardInput = cardNumbers[randomIndex];
         map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
         
         if (!cardArtMap.empty()) {
             
             for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;//Draws card.
             }
        } else {
            cout << "ERROR! If you see this message, the developer messed up." << endl;
        }

        //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player3 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
        Player3 += Points;//Adds card total.
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;//Shuffles deck.
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        //Player 3 makes a choice.
        cout << "What would you like to do, Player 3? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;//Draws card.
        }
    } else {
        cout << "ERROR! If you see this message, the developer messed up." << endl;
    }
    //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player3 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
    Player3 += Points;//Adds card total.
     cout << "Dealer's points: " << Dealer << endl;
     cout << "Player1 Points: " << Player1 << endl;
     cout << "Player2 Points: " << Player2 << endl;
     cout << "Player3 points: " << Player3 << endl;
         }
  } while (Choice != 'S');//Ends turn.
   
   }
    if (Players == 4) {//Checks if player 4 was invited.
   cout << "Player4 Cards" << endl;
     for (int i = 0; i < 2; ++i) {
        int randomIndex = rand() % numCards;//Shuffles deck.
         CardInput = cardNumbers[randomIndex];
         map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
         
         if (!cardArtMap.empty()) {
             
             for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;//Draws card.
             }
        } else {
            cout << "ERROR! If you see this message, the developer messed up." << endl;
        }

        //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player4 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
        Player4 += Points;//Adds card total
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
    cout << "Player4 Points: " << Player4 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;//Shuffles deck.
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        //Player 4 makes a move.
        cout << "What would you like to do, Player 4? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;//Draws card.
        }
    } else {
        cout << "ERROR! If you see this message, the developer messed up." << endl;
    }
    //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Player4 >= 11) {
            Points = 1;
        }else {
            Points = 11;
        }
    } else if (CardInput == "2" || CardInput == "15" || CardInput == "28" || CardInput == "41") {
        Points = 2;
    } else if (CardInput == "3" || CardInput == "16" || CardInput == "29" || CardInput == "42") {
        Points = 3;
    } else if (CardInput == "4" || CardInput == "17" || CardInput == "30" || CardInput == "43") {
        Points = 4;
    } else if (CardInput == "5" || CardInput == "18" || CardInput == "31" || CardInput == "44") {
        Points = 5;
    } else if (CardInput == "6" || CardInput == "19" || CardInput == "32" || CardInput == "45") {
        Points = 6;
    } else if (CardInput == "7" || CardInput == "20" || CardInput == "33" || CardInput == "46") {
        Points = 7;
    } else if (CardInput == "8" || CardInput == "21" || CardInput == "34" || CardInput == "47") {
        Points = 8;
    } else if (CardInput == "9" || CardInput == "22" || CardInput == "35" || CardInput == "48") {
        Points = 9;
    } else if (CardInput == "10" || CardInput == "23" || CardInput == "36" || CardInput == "49") {
        Points = 10;
    } else if (CardInput == "11" || CardInput == "24" || CardInput == "37" || CardInput == "50") {
        Points = 10;
    } else if (CardInput == "12" || CardInput == "25" || CardInput == "38" || CardInput == "51") {
        Points = 10;
    } else if (CardInput == "13" || CardInput == "26" || CardInput == "39" || CardInput == "52") {
        Points = 10;
    }
    Player4 += Points;//Adds card total.
     cout << "Dealer's points: " << Dealer << endl;
     cout << "Player1 Points: " << Player1 << endl;
     cout << "Player2 Points: " << Player2 << endl;
     cout << "Player3 points: " << Player3 << endl;
     cout << "Player4 Points: " << Player4 << endl;
         }
  } while (Choice != 'S');//Ends turn.
   }
  string winner;
//Compares the card total of all players.
     if (Player1 <= 21 && Player1 > Largest) {
         Largest = Player1;
         winner = "Player 1";
     }
     if (Player2 <= 21 && Player2 > Largest) {
         Largest = Player2;
         winner = "Player 2";
     }
     if (Player3 <= 21 && Player3 > Largest) {
         Largest = Player3;
         winner = "Player 3";
     }
     if (Player4 <= 21 && Player4 > Largest) {
         Largest = Player4;
         winner = "Player 4";
     }
     if (Dealer <= 21 && Dealer > Largest) {
         winner = "Dealer";
     }
     // Display the winner
     if (!winner.empty()) {
        cout << "The winner is: " << winner << endl;
     } else {
        cout << "No winner. It's a tie!" << endl;
     }
    
    return 0;//End of program
}