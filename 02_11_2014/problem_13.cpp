//
//  main.cpp
//  trash
//
//  Created by Anton Yakimenko on 02.11.14.
//  Copyright (c) 2014 Anton Yakimenko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
#define ULL unsigned long long
#define LL long long
int main(int argc, const char * argv[]) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    ULL a, k, p;
    cin >> a >> k >> p;
    ULL sum = 0, prev = 1;
    for(ULL i = 0; i<k; ++i)
    {
        prev = (prev*a)%p;
        sum += prev;
    }
    cout << sum;
    out.close();
    in.close();
    return 0;
}
