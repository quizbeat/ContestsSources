//
//  main.cpp
//  opencup_i
//
//  Created by Nikita Makarov on 11/10/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

int main(int argc, const char * argv[])
{
    //ifstream in("space-cat.in");
    //ofstream out("space-cat.out");
    
    int n;
    bool on_floor = true;
    long energy = 0;
    
    cin >> n;
    
    vector<long> roof(n + 1);
    vector<long> floor(n + 1);
    
    // input
    for (int i = 0; i < n; i++) {
        cin >> roof[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> floor[i];
    }
    
    roof[n] = roof[n - 1] - 1;
    floor[n] = floor[n - 1];
    
    bool no_solution = false;
    
    // main logic
    for (int i = 0; i < n + 1; i++) {
        
        if (i < (n - 1) && floor[i] < floor[i + 1] && roof[i] > roof[i + 1]) {
            no_solution = true;
            break;
        }
        
        if (on_floor) {
            int barrier_index = -1;
            for (int j = i + 1; j < n + 1; j++) {
                if (floor[j] > floor[j - 1]) {
                    barrier_index = j;
                    break;
                }
            }
            if (barrier_index == -1) { // can exit
                break;
            }
            // find barrier on roof
            int barrier_roof_index = i; // = i ???
            for (int j = barrier_index - 1; j > i; j--) { // barrier_index - 1????
                if (roof[j] < roof[j - 1]) { // !!!! <
                    barrier_roof_index = j;
                    break;
                }
            }
            // find minimal difference
            int min_diff_index = -1;
            long min_diff = LONG_MAX;
            for (int j = barrier_roof_index; j < barrier_index; j++) {
                if (roof[j] - floor[j] < min_diff) {
                    min_diff = roof[j] - floor[j];
                    min_diff_index = j;
                }
            }
            // jump at found min difference
            energy += min_diff;
            on_floor = false;
            i = barrier_index - 2; /// -1 ???
        } else {
            int barrier_index = -1;
            for (int j = i + 1; j < n + 1; j++) {
                if (roof[j] < roof[j - 1]) {
                    barrier_index = j;
                    break;
                }
            }
            if (barrier_index == -1) { // can exit
                break;
            }
            // find barrier on floor
            int barrier_floor_index = i; // = i ???
            for (int j = barrier_index - 1; j > i; j--) { // barrier_index - 1????
                if (floor[j] > floor[j - 1]) {
                    barrier_floor_index = j;
                    break;
                }
            }
            // find minimal difference
            int min_diff_index = -1;
            long min_diff = LONG_MAX;
            for (int j = barrier_floor_index; j < barrier_index; j++) {
                if (roof[j] - floor[j] < min_diff) {
                    min_diff = roof[j] - floor[j];
                    min_diff_index = j;
                }
            }
            // jump at found min difference
            energy += min_diff;
            on_floor = true;
            i = barrier_index - 2; // -1 ????
        }
    }
    
    if (no_solution) {
        cout << "-1" << endl;
    } else {
        cout << energy << endl;
    }
    
    //in.close();
    //out.close();
    
    return 0;
}
