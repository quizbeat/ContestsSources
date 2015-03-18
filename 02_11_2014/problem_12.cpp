//
//  main.cpp
//  trash
//
//  Created by Anton Yakimenko on 02.11.14.
//  Copyright (c) 2014 Anton Yakimenko. All rights reserved.
//

#include <iostream>
using namespace std;
#define ULL unsigned long long
int main(int argc, const char * argv[]) {
    ULL n, m;
    cin >> n >> m;
    ULL res = 1;
    for(int i=2; i<=n*2; i+=2)
    {
        res *= i;
    }
    if(res<m)
        cout << "Nope";
    else
        cout << "Harshat Mata";
    return 0;
}
