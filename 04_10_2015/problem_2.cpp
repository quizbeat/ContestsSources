//
//  main.cpp
//  opencup_2
//
//  Created by Nikita Makarov on 04/10/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct {
    string name;
    vector<string> losers;
} Team;

int main(int argc, const char * argv[]) {
    
    //ifstream in("/Users/makarov/Desktop/opencup_2/opencup_2/input.txt");
    //ofstream out("/Users/makarov/Desktop/opencup_2/opencup_2/output.txt");
    
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;
    in >> n;
    
    int t = 1;
    for (int i = 0; i < n; i++) {
        t *= 2;
    }
    
    map<int, vector<int> > teams; // first=team_name, second=losers_vector
    
    map<string, int> index_for_name;
    
    vector<pair<int, int> > pairs;
    
    vector<pair<int, int> > prev_pairs;
    
    vector<char> log(t - 1);
    
    for (int i = 0; i < t; i = i + 2) {
        string team_name_1, team_name_2;
        in >> team_name_1 >> team_name_2;
        
        index_for_name[team_name_1] = i;
        index_for_name[team_name_2] = i + 1;
        
        teams[i] = vector<int> ();
        teams[i + 1] = vector<int> ();
        
        pairs.push_back(make_pair(i, i + 1));
    }
    
    in.get();
    
    for (int i = 0; i < t - 1; i++) {
        char result = in.get();
        log[i] = result;
    }
    
    in.get();
    
    prev_pairs = pairs;
    pairs.clear();
    
    bool end = false;
    
    while (!end) {
        for (int i = 0; i < t / 2; i += 2) {
            int first_winner, first_looser;
            int second_winner, second_looser;
            
            if (log[i] == 'W') {
                first_winner = prev_pairs[i].first;
                first_looser = prev_pairs[i].second;
                teams[first_winner].push_back(first_looser);
                teams[first_winner].insert(teams[first_winner].end(), teams[first_looser].begin(), teams[first_looser].end());
            } else {
                first_winner = prev_pairs[i].second;
                first_looser = prev_pairs[i].first;
                teams[first_winner].push_back(first_looser);
                teams[first_winner].insert(teams[first_winner].end(), teams[first_looser].begin(), teams[first_looser].end());
            }
            
            if (i == t - 2) {
                end = true;
                break;
            }
            
            if (log[i + 1] == 'W') {
                second_winner = prev_pairs[i + 1].first;
                second_looser = prev_pairs[i + 1].second;
                teams[second_winner].push_back(second_looser);
                teams[second_winner].insert(teams[second_winner].end(), teams[second_looser].begin(), teams[second_looser].end());
            } else {
                second_winner = prev_pairs[i + 1].second;
                second_looser = prev_pairs[i + 1].first;
                teams[second_winner].push_back(second_looser);
                teams[second_winner].insert(teams[second_winner].end(), teams[second_looser].begin(), teams[second_looser].end());
            }
            
            pairs.push_back(make_pair(first_winner, second_winner));
        }
        
        log.erase(log.begin(), log.begin() + t / 2);
        
        prev_pairs = pairs;
        pairs.clear();
        
        t /= 2;
    }
    
    int q;
    in >> q;
    
    for (int i = 0; i < q; i++) {
        string t1, t2;
        in >> t1 >> t2;
        
        int index_1 = index_for_name[t1];
        int index_2 = index_for_name[t2];
        
        if (find(teams[index_1].begin(), teams[index_1].end(), index_2) != teams[index_1].end()) {
            out << "Win" << endl;
        } else if (find(teams[index_2].begin(), teams[index_2].end(), index_1) != teams[index_2].end()) {
            out << "Lose" << endl;
        } else {
            out << "Unknown" << endl;
        }
    }
    
    in.close();
    out.clear();
    
    return 0;
}
