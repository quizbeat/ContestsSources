//
//  main.cpp
//  problem_a
//
//  Created by Nikita Makarov on 27/09/15.
//  Copyright © 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct {
    int left;
    int rigth;
    int sum;
} error;

int main(int argc, const char * argv[])
{
    int n, m;
    cin >> n >> m;
    
    vector< map<string,int> > jag(n);
    for (int i = 0; i < n; i++) {
        jag[i]["w"] = 0;
        jag[i]["e"] = 0;
    }
    
    vector<error> errors (n + 1);
    errors[0].left = 0;
    errors[0].rigth = 0;
    errors[0].sum = 0;
    
    for (int i = 0; i < m; i++) {
        string features;
        cin >> features;
        for (size_t j = 0; j < features.size(); j++) {
            if (features[j] == 'W') {
                jag[j]["w"]++;
                errors[0].rigth++; // !!!!!!
            } else {
                jag[j]["e"]++;
            }
        }
    }
    
    errors[0].sum = errors[0].left + errors[0].rigth;
    
    int min_error = errors[0].rigth;
    int min_error_index = -1;
    
    for (int i = 1; i < n + 1; i++) {
        errors[i].left = 0;
        errors[i].rigth = 0;
        errors[i].sum = 0;
        
        errors[i].left = errors[i - 1].left + jag[i - 1]["e"];
        errors[i].rigth = errors[i - 1].rigth - jag[i - 1]["w"];
        errors[i].sum = errors[i].left + errors[i].rigth;
        
        if (errors[i].sum < min_error) {
            min_error = errors[i].sum;
            min_error_index = i;
        }
    }
    
    if (min_error_index == -1) {
        cout << "0 1" << endl;
    } else {
        cout << min_error_index << " " << min_error_index + 1 << endl;
    }
    
    return 0;
}
