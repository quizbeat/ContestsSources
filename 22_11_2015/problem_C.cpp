//
//  main.cpp
//  problem_c
//
//  Created by Nikita Makarov on 22/11/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    cin >> t;
    set<string> s;
    while (t--) {
        int n;
        cin >> n;
        string name;
        for (int i = 0; i < n; i++) {
            cin >> name;
            s.insert(name);
        }
        cout << s.size() << endl;
        s.clear();
    }
    
    return 0;
}
