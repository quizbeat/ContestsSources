//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <iomanip>
#include <limits>
#include <iostream>
#include <algorithm>

int main(){

    more_speed

    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");

    // for submit
    //ifstream in("input.txt");
    //ofstream out("output.txt");

    int n;
    cin >> n;
    int humans = 0;
    int aliens = 0;
    int fuckers = 0;
    int total = n;
    string answer;
    cin.get();

    while (n--) {
        getline(cin, answer);
        if (answer.find("blue") != -1 && answer.find("black") != -1) {
            humans++;
        }
        else if (answer.find("gold") != -1 && answer.find("white") != -1) {
            aliens++;
        }
        else {
            fuckers++;
        }
    }

    cout << setprecision(10) << (double)humans / total * 100 << endl;
    cout << setprecision(10) << (double)aliens / total * 100 << endl;
    cout << setprecision(10) << (double)fuckers / total * 100 << endl;

    //in.close();
    //out.close();

    return 0;
}
