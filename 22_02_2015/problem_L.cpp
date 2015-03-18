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

typedef struct {
    long gear;
    long a, b, c;
} eq;

int main() {
    // for submit
    ifstream in("input.txt");
    ofstream out("output.txt");

    int T;
    in >> T;
    while (T--) {
        long maxGear = 0;
        double maxValue = -1000000;
        int n;
        in >> n;
        for (int i = 1; i <= n; i++) {
            long a, b, c;
            in >> a >> b >> c;
            double max = (-1) * (((b * b) - (4 * (-a) * c)) / (4 * (-a)));
            if (max > maxValue) {
                maxValue = max;
                maxGear = i;
            }
        }
        out << maxGear << endl;
    }

    in.close();
    out.close();

    return 0;
}
