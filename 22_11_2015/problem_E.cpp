//
//  main.cpp
//  problem_c
//
//  Created by Nikita Makarov on 22/11/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

typedef struct {
    int number;
    int votes;
} Person;

bool cmp(const Person &a, const Person &b)
{
    return a.votes > b.votes;
}

using namespace std;

int main(int argc, const char * argv[])
{
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int total_votes = 0;
        
        vector<Person> persons(n);
        for (int i = 0; i < n; i++) {
            persons[i].number = i + 1;
            cin >> persons[i].votes;
            total_votes += persons[i].votes;
        }
        
        sort(persons.begin(), persons.end(), cmp);
        
        int top_votes = persons[0].votes;
        int half_votes = total_votes / 2;
        
        if (t == 1) {
            cout << " " << endl;
        }
        
        if (top_votes > half_votes) {
            if (persons[1].votes != top_votes) {
                cout << "Victory " << persons[0].number << endl;
            } else {
                cout << "Tie" << endl;
            }
        } else {
            if (persons[1].votes != top_votes) {
                cout << "Leader " << persons[0].number << endl;
            } else {
                cout << "Tie" << endl;
            }
        }
    }
    
    return 0;
}
