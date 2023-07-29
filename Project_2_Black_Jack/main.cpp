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
map<int, string> readCardArt(const string& filename, const string& TestInput) {
    ifstream inputFile(filename);
    map<int, std::string> CardArt;
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
    
    
    return 0;//End of program
}