//
//  main.cpp
//  OpenCupG
//
//  Created by Nikita Makarov on 13/09/15.
//  Copyright (c) 2015 Nikita Makarov. All rights reserved.
//

#include <iostream>

using namespace std;

long gcd (long a, long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    long n, k;
    cin >> n >> k;
    cout << gcd(n, k);
    return 0;
}
