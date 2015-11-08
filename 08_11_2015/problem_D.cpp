//
//  main.cpp
//  opencup
//
//  Created by Nikita Makarov on 08/11/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, const char * argv[])
{
    
    int n;
    cin >> n;
    
    vector<int> gtu(n);
    vector<int> tsu(n);
    
    int val;
    
    for (int i = 0; i < n; i++) {
        cin >> val;
        gtu[i] = val;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> val;
        tsu[i] = val;
    }
    
    sort(gtu.begin(), gtu.end(), greater<int>());
    sort(tsu.begin(), tsu.end(), greater<int>());
    
    int gtu_score = 0;
    int tsu_score = 0;
    
    vector<int> tsu_search = tsu;
    
    int next_start_pos = 0;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = next_start_pos; j < n; j++) {
            if (gtu[i] > tsu_search[j]) {
                gtu_score++;
                tsu_search[j] = INT_MAX;
                found = true;
                next_start_pos = j + 1;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    
    next_start_pos = 0;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = next_start_pos; j < n; j++) {
            if (tsu[i] > gtu[j]) {
                tsu_score++;
                gtu[j] = INT_MAX;
                found = true;
                next_start_pos = j + 1;
                break;
            }
        }
        if (!found) {
            break;
        }
    }
    
    cout << gtu_score << " " << tsu_score << endl;
    
    return 0;
}
