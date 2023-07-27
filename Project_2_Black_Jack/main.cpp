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

using namespace std; //Standard Namespace

//Main Function
int main(int argc, char** argv) {
    //Define Variables
    string CardNum; //(A,2,3,4,5,6,7,8,9,10,J,Q,K)
    char Suit; //(H)earts,(D)iamonds,(C)lubs,(S)pades
    string CardNum2;
    char Suit2;
    int Choice;
    int Total;
    int Dealer;
    
    //I wanted the text-based game of BlackJack to look nice, so I made ASCII art.
    string cardArt = "";
    if (CardNum == "A" || CardNum == "a") {
            cardArt += "  _______\n";
            cardArt += " |A      |\n";
            cardArt += " |       |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |       |\n";
            cardArt += " |______V|\n";
        } else if (CardNum == "2") {
            cardArt += "  _______\n";
            cardArt += " |2      |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |       |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |______Z|\n";
        } else if (CardNum == "3") {
            cardArt += "  _______\n";
            cardArt += " |3      |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |______E|\n";
        } else if (CardNum == "4") {
            cardArt += "  _______\n";
            cardArt += " |4      |\n";
            cardArt += " |  ♦ ♦ |\n";
            cardArt += " |       |\n";
            cardArt += " |  ♦ ♦ |\n";
            cardArt += " |______h|\n";
        } else if (CardNum == "5") {
            cardArt += "  _______\n";
            cardArt += " |5      |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |   ♦   |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |______S|\n";
        } else if (CardNum == "6") {
            cardArt += "  _______\n";
            cardArt += " |6      |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |______9|\n";
        } else if (CardNum == "7") {
            cardArt += "  _______\n";
            cardArt += " |7      |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " | ♦ ♦ ♦ |\n";
            cardArt += " |  ♦ ♦  |\n";
            cardArt += " |______L|\n";
        } else if (CardNum == "8") {
            cardArt += "  _______\n";
            cardArt += " |8      |\n";
            cardArt += " | ♦ ♦ ♦|\n";
            cardArt += " |  ♦ ♦ |\n";
            cardArt += " | ♦ ♦ ♦|\n";
            cardArt += " |______8|\n";
        } else if (CardNum == "9") {
            cardArt += "  _______\n";
            cardArt += " |9      |\n";
            cardArt += " | ♦ ♦ ♦|\n";
            cardArt += " | ♦ ♦ ♦|\n";
            cardArt += " | ♦ ♦ ♦|\n";
            cardArt += " |______6|\n";
        } else if (CardNum == "10") {
            cardArt += "  ________\n";
            cardArt += " |10      |\n";
            cardArt += " | ♦ ♦ ♦ |\n";
            cardArt += " |♦ ♦ ♦ ♦|\n";
            cardArt += " | ♦ ♦ ♦ |\n";
            cardArt += " |______OI|\n";
        } else if (CardNum == "J" || CardNum == "j") {
            cardArt += "  _______\n";
            cardArt += " |J    ww|\n";
            cardArt += " |   ♦ {)|\n";
            cardArt += " |   | % |\n";
            cardArt += " |     % |\n";
            cardArt += " |____%%[|\n";
        } else if (CardNum == "Q" || CardNum == "q") {
            cardArt += "  _______\n";
            cardArt += " |Q    ww|\n";
            cardArt += " |   ♦ {(|\n";
            cardArt += " |   | %%|\n";
            cardArt += " |    %%%|\n";
            cardArt += " |___%%%0|\n";
        } else if (CardNum == "K" || CardNum == "k") {
            cardArt += "  _______\n";
            cardArt += " |K    WW|\n";
            cardArt += " |   ♦ {)|\n";
            cardArt += " |   | %%|\n";
            cardArt += " |    %%%|\n";
            cardArt += " |___%%%>|\n";
        } else if (CardNum == "B" || CardNum == "b") {
            cardArt += "  _______\n";
            cardArt += " |VVVVVVV|\n";
            cardArt += " |}}:::{{|\n";
            cardArt += " |}}:::{{|\n";
            cardArt += " |}}:::{{|\n";
            cardArt += " |~~~~~~~|\n";
        } else {//This else statement should only appear if the developer (me) messed up.
            cout << "ERROR! Something went wrong!" << endl;
            return 1;
    }
    //Replaces the default diamond suit with correct suit.
    size_t found = cardArt.find("♦");
    while (found != string::npos) {
    switch (toupper(Suit)) {
        case 'H':
            cardArt.replace(found, 3, "♥");
            break;
        case 'D':
            cardArt.replace(found, 3, "♦");
            break;
        case 'C':
            cardArt.replace(found, 3, "♣");
            break;
        case 'S':
            cardArt.replace(found, 3, "♠");
            break;
        default://This default statement should only appear if the developer (me) messed up.
            cout << "ERROR! Something went wrong!" << endl;
            return 1;
    }
    found = cardArt.find("♦", found + 1); // Move to the next ♦ symbol
    }
    //Output
    cout << "The " << CardNum << " " << Suit << " card:" << endl;//Outputs card in text form in case the art messes up.
    cout << cardArt << endl;//Outputs ASCII art
    cout << "The " << CardNum2 << " " << Suit2 << " card:" << endl;//Outputs card in text form in case the art messes up.
    cout << cardArt2 << endl;//Outputs ASCII art
    cout << "You have " << Total << " ." << endl;//Adds both cards.
    cout << "What would you like to do? ((H)it or (S)tand)" << endl;
    char Choice2;
    cin >> Choice2;//Allows the user to add another card.
    //Do to current limitations, the (H)it choice is predefined.
    if (Choice2 == 'H' || Choice2 == 'h'){
        CardNum = "5";//Rewrites the CardNum variable.
        Suit = 'C';//Rewrites the Suit variable.
        Total += 5;//Adds the new card to the total.
        //Outputs new variables and total.
        cout << "The " << CardNum << " " << Suit << " card:" << endl;
        cout << cardArt << endl;
        cout << "You have " << Total << " ." << endl;
        cout << "What would you like to do? ((H)it or (S)tand)" << endl;
        cin >> Choice2;
        if (Choice2 == 'H' || Choice2 == 'h'){
        CardNum = "10";//Rewrites the CardNum variable.
        Suit = 'H';//Rewrites the Suit variable.
        Total += 10;//Adds the new card to the total.
        //Outputs new variables and total.
        cout << "The " << CardNum << " " << Suit << " card:" << endl;
        cout << cardArt << endl;
        cout << "You have " << Total << " ." << endl;
        cout << "What would you like to do? ((H)it or (S)tand)" << endl;
        cin >> Choice2;
         if (Choice2 == 'H' || Choice2 == 'h'){
        CardNum = "2";//Rewrites the CardNum variable.
        Suit = 'C';//Rewrites the Suit variable.
        Total += 2;//Adds the new card to the total.
        //Outputs new variables and total.
        cout << "The " << CardNum << " " << Suit << " card:" << endl;
        cout << cardArt << endl;
        cout << "You have " << Total << " ." << endl;
        //Since this program is predefined, it automatically chooses "S" after 2 additional cards.
        //This if statement tells you if you won.
        if (Total <= Dealer) {
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, Dealer wins. " << Dealer << endl;
        } else if (Total <= 21 && Total > Dealer) {
            cout << "Your card count is " << Total << endl;
            cout << "CONGRATULATIONS! YOU WIN!" << endl;
        } else {
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, you went BUST." << endl;
        }
    } else if (Choice2 == 'S' || Choice2 == 's') {
        if (Total <= Dealer) {//This if statement tells you if you won.
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, Dealer wins. " << Dealer << endl;
        } else if (Total <= 21 && Total > Dealer) {
            cout << "Your card count is " << Total << endl;
            cout << "CONGRATULATIONS! YOU WIN!" << endl;
        } else {
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, you went BUST." << endl;
        }
    }
    } else if (Choice2 == 'S' || Choice2 == 's') {
        if (Total <= Dealer) {//This if statement tells you if you won.
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, Dealer wins. " << Dealer << endl;
        } else if (Total <= 21 && Total > Dealer) {
            cout << "Your card count is " << Total << endl;
            cout << "CONGRATULATIONS! YOU WIN!" << endl;
        } else {
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, you went BUST." << endl;
        }
    }
    } else if (Choice2 == 'S' || Choice2 == 's') {
        if (Total <= Dealer) {//This if statement tells you if you won.
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, Dealer wins. " << Dealer << endl;
        } else if (Total <= 21 && Total > Dealer) {
            cout << "Your card count is " << Total << endl;
            cout << "CONGRATULATIONS! YOU WIN!" << endl;
        } else {
            cout << "Your card count is " << Total << endl;
            cout << "Sorry, you went BUST." << endl;
        }
    }
    return 0;//End of program
}