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

/* This comment section is where I keep my copy/paste code.
 * First time use.
 * map<int, string> cardArtMap = readCardArt("card_art.txt", TestInput);
 * Second time use.
 * cardArtMap = readCardArt("card_art.txt", TestInput);
 * Test Output.
 * if (!cardArtMap.empty()) {
 *       cout << "Character found. The six lines after it are:" << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
        }
    } else {
        cout << "Character not found in the file." << endl;
    }
 */

#include <iostream> //Input and Output
#include <string> //Adds the string variable
#include <cctype> //Adds toupper()
#include <fstream> //Can read external files
#include <unordered_map>
#include <map>
#include <cstdlib>
#include <array>
#include <vector>

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
    
    cout << "How many players are playing? (Maximum: 4) ";
    cin >> Players;
    if (Players > 4 || Players < 1) {
        cout << "INVALID INPUT!";
        return 0;
    }
    //Random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    //Card Deck.
    array<string, 52> cardNumbers = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
        "21", "22", "23", "24", "25", "26", "27", "28", "29", "30",
        "31", "32", "33", "34", "35", "36", "37", "38", "39", "40",
        "41", "42", "43", "44", "45", "46", "47", "48", "49", "50",
        "51", "52"
    };
    const int numCards = cardNumbers.size();
    int randomIndex = std::rand() % numCards;
    // Output four random cards before the loop
    cout << "Dealer's Cards" << endl;
    for (Dealer = 0; Dealer < 17; Dealer += Points) {
        int randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;
            }
            //Points Calculations
    if (CardInput == "1" || CardInput == "14" || CardInput == "27" || CardInput == "40") {
        if (Dealer >= 11) {
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
        } else {
            cout << "ERROR! If you see this message, the developer messed up." << endl;
        }
    }
    if (Players == 1 || Players == 2 || Players == 3 || Players == 4) {
        
    cout << "Player1 Cards" << endl;
    for (int i = 0; i < 2; ++i) {
        int randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;
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
        Player1 += Points;
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 points: " << Player1 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        
        cout << "What would you like to do, Player 1? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
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
    Player1 += Points;
    cout << "Dealer's Points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
        }
  } while (Choice != 'S');
  
  }
  //Player 2
    if (Players == 2 || Players == 3 || Players == 4) {
        
  cout << "Player2 Cards" << endl;
    for (int i = 0; i < 2; ++i) {
        int randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;
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
        Player2 += Points;
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 points: " << Player1 << endl;
    cout << "Player2 points: " << Player2 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        
        cout << "What would you like to do Player 2? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
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
    Player2 += Points;
    cout << "Dealer's Points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
        }
  } while (Choice != 'S');
  
  }
    if (Players == 3 || Players == 4) {
        
  cout << "Player3 Cards" << endl;
    for (int i = 0; i < 2; ++i) {
        int randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;
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
        Player3 += Points;
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        
        cout << "What would you like to do, Player 3? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
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
    Player3 += Points;
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
        }
  } while (Choice != 'S');
  
  }
    if (Players == 4) {
  cout << "Player4 Cards" << endl;
    for (int i = 0; i < 2; ++i) {
        int randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
        
        if (!cardArtMap.empty()) {
            
            for (const auto& entry : cardArtMap) {
                cout << entry.second << endl;
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
        Player4 += Points;
    }
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
    cout << "Player4 Points: " << Player4 << endl;
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        
        cout << "What would you like to do, Player 4? ((S)tand or (H)it)" << endl;
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'H'){
    if (!cardArtMap.empty()) {
        cout << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
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
    Player4 += Points;
    cout << "Dealer's points: " << Dealer << endl;
    cout << "Player1 Points: " << Player1 << endl;
    cout << "Player2 Points: " << Player2 << endl;
    cout << "Player3 points: " << Player3 << endl;
    cout << "Player4 Points: " << Player4 << endl;
        }
  } while (Choice != 'S');
  }
    
  std::string winner;

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

    // Compare against the dealer's hand
    if (Dealer <= 21 && Dealer > Largest) {
        winner = "Dealer";
    }

    // Display the winner
    if (!winner.empty()) {
        std::cout << "The winner is: " << winner << std::endl;
    } else {
        std::cout << "No winner. It's a tie!" << std::endl;
    }
    
    return 0;//End of program
}