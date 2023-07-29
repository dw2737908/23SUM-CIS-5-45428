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
    
    map<int, string> cardArtMap = readCardArt("card_art.txt", CardInput);
    do {
        randomIndex = std::rand() % numCards;
        CardInput = cardNumbers[randomIndex];
        cardArtMap = readCardArt("card_art.txt", CardInput);
        
        cout << "Would you like a card? ";
        cin >> Choice;
        Choice = toupper(Choice);
        if (Choice == 'Y'){
    if (!cardArtMap.empty()) {
        cout << "Character found " << CardInput << ". The six lines after it are:" << endl;
        for (const auto& entry : cardArtMap) {
            cout << entry.second << endl;
        }
    } else {
        cout << "ERROR! If you see this message, the developer messed up." << endl;
    }
        }
  } while (Choice == 'Y');
    
    return 0;//End of program
}