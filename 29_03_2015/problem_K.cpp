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

//int n, m;

//vector<bool> used(n * m, false);
//vector<vector<int> > g(n * m, vector<int>());

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

typedef struct {
    int i, j;
} point;

int main(){
    
    more_speed
    
    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");
    
    // for submit
    //ifstream in("input.txt");
    //ofstream out("output.txt");

    int n, m;
    cin >> n >> m;

    int x_num = 0;
    int k_num = 0;
    
    char symb;
    
    vector<bool> used(n * m, false);
    vector<vector<int> > g(n * m, vector<int>());
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> symb;
            //used[i][j] = false;
            if (symb == '#') {
                used[i * m + j] = true;
            }
            else if (symb == 'K') {
                k_num = i * m + j;
                used[i * m + j] = true;
            }
            else if (symb == 'X') {
                x_num = i * m + j;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int to = i * m + j;
            
            if (i - 2 >= 0 && j - 1 >= 0)
                g[to].push_back((i - 2) * m + (j - 1));
            if (i - 2 >= 0 && j + 1 < m)
                g[to].push_back((i - 2) * m + (j + 1));
            
            if (i - 1 >= 0 && j - 2 >= 0)
                g[to].push_back((i - 1) * m + (j - 2));
            if (i + 1 < n && j - 2 >= 0)
                g[to].push_back((i + 1) * m + (j - 2));
            
            if (i + 2 < n && j - 1 >= 0)
                g[to].push_back((i + 2) * m + (j - 1));
            if (i + 2 < n && j + 1 < m)
                g[to].push_back((i + 2) * m + (j + 1));
            
            if (i - 1 >= 0 && j + 2 < m)
                g[to].push_back((i - 1) * m + (j + 2));
            if (i + 1 < n && j + 2 < m)
                g[to].push_back((i + 1) * m + (j + 2));
        }
    }
    
    queue<int> ways;
    used[k_num] = true;
    ways.push(k_num);

    vector<int> d(n * m), p(n * m);
    p[k_num] = -1;
    
    while (!ways.empty()) {
        int v = ways.front();
        ways.pop();
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                ways.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    
    if (!used[x_num])
        cout << "-1" << endl;
    else {
        vector<int> path;
        for (int v = x_num; v!= -1; v = p[v])
            path.push_back (v);
        cout << path.size() - 1 << endl;
    }
    
    //in.close();
    //out.close();
    
    return 0;
}
