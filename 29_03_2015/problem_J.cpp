//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <limits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <cctype>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>

#define LL  long long
#define ULL unsigned long long
#define EPS 1e-11

#define more_speed ios_base::sync_with_stdio(false);

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

// check for prime
bool prime(ULL n) {
    for (ULL i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

long gcd(long a, long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ULL lcm(ULL a, ULL b) {
	return a / gcd(a, b) * b;
}

// comparators
bool cmpPairAscendingByFirst(const pair<ULL, ULL> &a, const pair<ULL, ULL> &b) {
    return a.first < b.first;
}

bool cmpPairDescendingByFirst(const pair<ULL, ULL> &a, const pair<ULL, ULL> &b) {
    return a.first > b.first;
}

bool cmpPairAscendingBySecond(const pair<LL, LL> &a, const pair<LL, LL> &b) {
    return a.second < b.second;
}

bool cmpPairDescendingBySecond(const pair<LL, LL> &a, const pair<LL, LL> &b) {
    return a.second > b.second;
}

// check for char
bool isChar(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// factorial
ULL fac(ULL n) {
    return (n == 0) ? 1 : n * fac(n - 1);
}

/*
vector<set<LL> > g;
vector<char> color;
vector<LL> p;
LL cycle_st, cycle_end;

bool dfs (LL v) {
    color[v] = 1;
    for (set<LL>::iterator i = g[v].begin(); i != g[v].end(); i++) {
        LL to = *i;
        if (color[to] == 0) {
            p[to] = v;
            if (dfs(to)) return true;
        }
        else if (color[to] == 1){
            cycle_st = to;
            cycle_end = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
 */

int main(){
    
    more_speed
    
    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");
    
    // for submit
    //ifstream in("input.txt");
    //ofstream out("output.txt");

    long k;
    cin >> k;
    long length = (k - 1) / 25 + 2;
    
    string s = "";
    for (long i = 0; i < length; i++) {
        if (i  % 2)
            s += "z";
        else
            s += "a";
    }
    
    if (length > 2) {
        s[1] = (char)('n' + (k - 25 * (length - 2)) / 2);
        long last = s.size() - 1;
        if (s[last] == 'z' && k % 2 == 0) {
            s[last] = 'y';
        }
        else if (s[last] == 'a' && k % 2 == 1) {
            s[last] = 'b';
        }
    }
    else {
        s[0] = 'a';
        s[1] = 'a' + k;
    }
    
    cout << s << endl;
    
    
    //in.close();
    //out.close();
    
    return 0;
}
