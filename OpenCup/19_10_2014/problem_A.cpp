//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <iomanip>
#include <iostream>
#include <algorithm>

bool isChar(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int num(string s) {
    if      (s == "white" || s == "barabashka") return 0;
    else if (s == "blue"  || s == "book")       return 1;
    else if (s == "red"   || s == "chair")      return 2;
    else if (s == "gray"  || s == "mouse")      return 3;
    else return 4;
}
 
int main() {
    
    more_speed
    ifstream in("barabashka.in");
    ofstream out("barabashka.out");
    
    string white = "white",
           blue  = "blue",
           red   = "red",
           gray  = "gray",
           green = "green";
    string barab = "barabashka",
           book  = "book",
           chair = "chair",
           mouse = "mouse",
           bottle = "bottle";
    
    string current;
    string firstColor, firstObject;
    string secondColor, secondObject;
    bool needFirstColor, needFirstObject;
    bool needSecondColor, needSecondObject;
    bool complete;
    
    
    for (int i = 0; i < 5; i++) {
        char cSymb = in.get();
        bool used[5] = {false};
        needFirstColor   = true;
        needFirstObject  = false;
        needSecondColor  = false;
        needSecondObject = false;
        complete         = false;
        
        while (cSymb != '\0') { // считывние строки
            while (cSymb != ' ' && isChar(cSymb)) { // считывание слова
                current += tolower(cSymb);
                cSymb = in.get();
            }
            if (needFirstColor) {
                if (current == white)      { firstColor = white; needFirstObject = true; needFirstColor = false; }
                else if (current == blue)  { firstColor = blue;  needFirstObject = true; needFirstColor = false; }
                else if (current == red)   { firstColor = red;   needFirstObject = true; needFirstColor = false; }
                else if (current == gray)  { firstColor = gray;  needFirstObject = true; needFirstColor = false; }
                else if (current == green) { firstColor = green; needFirstObject = true; needFirstColor = false; }
            }
            else if (needFirstObject) {
                if (current == barab)       { firstObject = barab;  needSecondColor = true; needFirstObject = false; }
                else if (current == book)   { firstObject = book;   needSecondColor = true; needFirstObject = false; }
                else if (current == chair)  { firstObject = chair;  needSecondColor = true; needFirstObject = false; }
                else if (current == mouse)  { firstObject = mouse;  needSecondColor = true; needFirstObject = false; }
                else if (current == bottle) { firstObject = bottle; needSecondColor = true; needFirstObject = false; }
            }
            else if (needSecondColor) {
                if (current == white)      { secondColor = white; needSecondObject = true; needSecondColor = false; }
                else if (current == blue)  { secondColor = blue;  needSecondObject = true; needSecondColor = false; }
                else if (current == red)   { secondColor = red;   needSecondObject = true; needSecondColor = false; }
                else if (current == gray)  { secondColor = gray;  needSecondObject = true; needSecondColor = false; }
                else if (current == green) { secondColor = green; needSecondObject = true; needSecondColor = false; }
            }
            else if (needSecondObject) {
                if (current == barab)       { secondObject = barab;  complete = true; needSecondObject = false; }
                else if (current == book)   { secondObject = book;   complete = true; needSecondObject = false; }
                else if (current == chair)  { secondObject = chair;  complete = true; needSecondObject = false; }
                else if (current == mouse)  { secondObject = mouse;  complete = true; needSecondObject = false; }
                else if (current == bottle) { secondObject = bottle; complete = true; needSecondObject = false; }
            }
            if (complete) {
                cSymb = '\0'; // все найдено, уходим

                used[num(firstColor)] = true;
                used[num(firstObject)] = true;
                used[num(secondColor)] = true;
                used[num(secondObject)] = true;
                
                if ((firstColor == white && firstObject == barab) ||
                    (secondColor == white && secondObject == barab)) { out << white << " " << "Barabashka" << endl; }
                
                else if ((firstColor == blue && firstObject == book) ||
                         (secondColor == blue && secondObject == book)) { out << blue << " " << book << endl; }
                
                else if ((firstColor == red && firstObject == chair) ||
                         (secondColor == red && secondObject == chair)) { out << red << " " << chair << endl; }
                
                else if ((firstColor == gray && firstObject == mouse) ||
                         (secondColor == gray && secondObject == mouse)) { out << gray << " " << mouse << endl; }
                
                else if ((firstColor == green && firstObject == bottle) ||
                         (secondColor == green && secondObject == bottle)) { out << green << " " << bottle << endl; }
                
                else {
                    for (int j = 0; j < 5; j++) {
                        if (!used[j]) {
                            if (j == 0) { out << white << " " << "Barabashka" << endl; }
                            else if (j == 1) { out << blue << " " << book << endl; }
                            else if (j == 2) { out << red << " " << chair << endl; }
                            else if (j == 3) { out << gray << " " << mouse << endl; }
                            else             { out << green << " " << bottle << endl; }
                            break;
                        }
                    }
                }
                
                
            }
            current.clear();
            if (cSymb != '\0') cSymb = in.get();
        }
    }
    return 0;
}