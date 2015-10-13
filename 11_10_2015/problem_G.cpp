//
//  main.cpp
//  opencup_g
//
//  Created by Nikita Makarov on 11/10/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

bool desk_is_correct(int desk[4][4])
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int targer_i = (desk[i][j] - 1) / 4;
            int targer_j = (desk[i][j] - 1) % 4;
            if (i != targer_i || j != targer_j) {
                return false;
            }
        }
    }
    return true;
}

char character_for_num(int num)
{
    return char('a' + num);
}

int main(int argc, const char * argv[])
{
    stringstream ss;
    
    ifstream in("puzzle-swap.in");
    ofstream out("puzzle-swap.out");
    
    int desk[4][4] = {0};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            in >> desk[i][j];
        }
    }
    
    int moves = 0;
    vector<string> log;
    
    // find all wrong pairs
    for (int i1 = 0; i1 < 4; i1++) {
        for (int j1 = 0; j1 < 4; j1++) {
            for (int i2 = 0; i2 < 4; i2++) {
                for (int j2 = 0; j2 < 4; j2++) {
                    if (i1 != i2 || j1 != j2) {
                        int targer_i1 = (desk[i1][j1] - 1) / 4;
                        int targer_j1 = (desk[i1][j1] - 1) % 4;
                        int targer_i2 = (desk[i2][j2] - 1) / 4;
                        int targer_j2 = (desk[i2][j2] - 1) % 4;
                        if (targer_i1 == i2 && targer_j1 == j2 &&
                            targer_i2 == i1 && targer_j2 == j1) {
                            moves++;
                            swap(desk[i1][j1], desk[i2][j2]);
                            ss << character_for_num(i1) << j1 + 1 << "-" << character_for_num(i2) << j2 + 1 << endl;
                            string s;
                            ss >> s;
                            log.push_back(s);
                        }
                    }
                }
            }
        }
    }
    
    while (!desk_is_correct(desk)) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int targer_i = (desk[i][j] - 1) / 4;
                int targer_j = (desk[i][j] - 1) % 4;
                if (i != targer_i || j != targer_j) {
                    moves++;
                    swap(desk[i][j], desk[targer_i][targer_j]);
                    ss << character_for_num(i) << j + 1 << "-" << character_for_num(targer_i) << targer_j + 1 << endl;
                    string s;
                    ss >> s;
                    log.push_back(s);
                }
            }
        }
    }
    
    out << moves << endl;
    for (size_t i = 0; i < log.size(); i++) {
        out << log[i] << endl;
    }
    
    in.close();
    out.close();
    
    return 0;
}
