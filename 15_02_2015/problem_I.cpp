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

    more_speed

    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");

    // for submit
    ifstream in("jam.in");
    //ofstream out("kickdown.out");

    int T;
    in >> T;

    while (T--) {
        int m, zashli, vishli;
        long ans = 0;
        long buf = 0;
        in >> m;
        for (int i = 0; i < m; i++) {
            in >> zashli >> vishli;
            zashli += buf;
            int diff = zashli - vishli;
            if (diff < 0) {
                ans += diff * (-1);
                buf = 0;
            }
            else {
                buf = diff;
            }
        }
        cout << ans << endl;
    }

    in.close();
    //out.close();

    return 0;
}
