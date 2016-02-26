//
//  main.cpp
//  problem_o
//
//  Created by Nikita Makarov on 14/02/16.
//  Copyright © 2016 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    long suit;
    long cost;
    int id;
} Card;

bool cmp_suit(const Card &a, const Card &b)
{
    return a.suit < b.suit;
}

bool cmp_cost(const Card &a, const Card &b)
{
    return a.cost < b.cost;
}

int main()
{
    int n;
    cin >> n;
    
    vector<Card> hand(n);
    
    for (int i = 0; i < n; i++) {
        cin >> hand[i].suit >> hand[i].cost;
        hand[i].id = i + 1;
    }
    
    stable_sort(hand.begin(), hand.end(), cmp_cost);
    stable_sort(hand.begin(), hand.end(), cmp_suit);
    
    vector< pair<int, int> > output;
    
    vector< vector<int> > jazz;
    
    for (int i = 1; i <= n; i++) {
        vector<int> temp;
        temp.push_back(hand[i - 1].id);
        while (i < n && hand[i].suit == hand[i - 1].suit) {
            temp.push_back(hand[i].id);
            i++;
        }
        jazz.push_back(temp);
    }
    
    for (size_t i = 0; i < jazz.size(); i++) {
        if (jazz[i].size() < 2) {
            cout << "-1" << endl;
            return 0;
        } else {
            output.push_back(make_pair(jazz[i][0], jazz[i][1]));
        }
    }
    
    cout << output.size() << endl;
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i].first << " " << output[i].second << endl;
    }
    
    return 0;
}
