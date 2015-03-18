//
//  main.cpp
//  hashString
//
//  Created by Nikita Makarov on 01/02/15.
//  Copyright (c) 2015 HardCode. All rights reserved.
//

#include <iostream>

using namespace std;

long min_cyclic_shift (string s) {
    s += s;
    long n = (long) s.length();
    long i = 0, ans = 0;
    while (i < n/2) {
        ans = i;
        long j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                ++k;
            ++j;
        }
        while (i <= k)  i += j - k;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    long n;
    string s;
    cin >> n >> s;
    long answer = min_cyclic_shift(s);
    cout << answer + 1 << endl;
    return 0;
}
