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

#define LL  long long
#define ULL unsigned long long
#define EPS 1e-11

#define more_speed ios_base::sync_with_stdio(false);

using namespace std;

bool g(int x, int y) {

    if (x == y) return true;

    if (x == 1) {
        return true;
    }
    else if (x == 2) {
        if (y == 3 || y == 5 || y == 6 || y == 8 || y == 9 || y == 0) return true;
    }
    else if (x == 3) {
        if (y == 6 || y == 9) return true;
    }
    else if (x == 4) {
        if (y >= 4 || y == 0) return true;
    }
    else if (x == 5) {
        if (y == 6 || y == 8 || y == 9 || y == 0) return true;
    }
    else if (x == 6) {
        if (y == 9) return true;
    }
    else if (x == 7) {
        if (y >= 7 || y == 0) return true;
    }
    else if (x == 8) {
        if (y == 9 || y == 0) return true;
    }
    return false;
}

int main() {

    more_speed

    int z[] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1};

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (z[n] == 1) {
            cout << n << endl;
        }
        else {
            int y = n;
            int x = n;
            while (z[x] == 0) {
                x++;
            }
            while (z[y] == 0) {
                y--;
            }
            if (n - y > x - n) {
                cout << x << endl;
            }
            else {
                cout << y << endl;
            }
        }
    }

    return 0;
}
