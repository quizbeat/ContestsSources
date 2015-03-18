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

int main() {
    // for submit
    ifstream in("input.txt");
    ofstream out("output.txt");

    long T;
    in >> T;
    while (T--) {
        long dev, runs, execParallel, execCurrent;
        in >> dev >> runs >> execCurrent >> execParallel;
        long keepTime, rewriteTime;
        keepTime = runs * execCurrent;
        rewriteTime = dev + runs * execParallel;
        //cout << "keep time " << keepTime << endl;
        //cout << "rewrite time " << rewriteTime << endl;
        if (keepTime < rewriteTime) {
            out << "Keep" << endl;
        }
        else if (keepTime > rewriteTime) {
            out << "Rewrite" << endl;
        }
        else {
            out << "Flip a Coin" << endl;
        }
    }

    in.close();
    out.close();

    return 0;
}
