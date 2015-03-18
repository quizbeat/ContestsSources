//
//  main.cpp
//  contest
//
//  Created by Nikita Makarov on 21/07/14.
//  Copyright (c) 2014 quiz.corp. All rights reserved.
//

#include <iomanip>
#include <limits>
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

// check for prime
bool prime(ULL n) {
    for (ULL i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

ULL gcd(ULL a, ULL b){
    if (b == 0)
        return a;
    return gcd(b, a%b);
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

ifstream in("killthepsu.in");
ofstream out("killthepsu.out");

//ifstream in("/Users/air/Documents/dev/contest/contest/in");
//ofstream out("/Users/air/Documents/dev/contest/contest/out");

class item {
public:
    string name;
    virtual void message() = 0;
};

class cat1 : public item {
public:
    void message() {
        out << "wake " << name << endl;
    }
    cat1(string n) {
        name = n;
    }
};

class cat2 : public item {
public:
    bool load;
    void message() {
        if (load) {
            out << "unload ";
            load = false;
        }
        else {
            out << "load ";
            load = true;
        }
        out << name << endl;
    }
    cat2(string n) {
        name = n;
        load = false;
    }
};

int reserve = 20;
bool nextIter = false;

class cat3 : public item {
public:
    int power;
    void message() {
        if (reserve) {
            reserve -= 10;
            out << "power fail on " << name << endl;
            return;
        }
        power -= 10;
        if (power > 10) {
            out << "power fail on " << name << endl;
        }
        else if (power <= 10) {
            out << "buy the new PSU" << endl;
            nextIter = true;
        }
    }
    cat3(string n) {
        power = 100;
        name = n;
    }
};

int main() {
    
    more_speed
    
    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");
    
    // for submit
    //ifstream in("kickdown.in");
    //ofstream out("kickdown.out");

    int t;
    in >> t;
    
    for (int k = 0; k < t; k++) {
        reserve = 20;
        map<string, item *> system;
        int a, b, c, d;
        in >> a >> b >> c >> d;
        string name;
        in.get();
        
        for (int i = 0; i < a; i++) {
            getline(in, name);
            item *newItem = new cat1(name);
            system[name] = newItem;
            //cout << i << " " << name << endl;
        }
        
        for (int i = 0; i < b; i++) {
            getline(in, name);
            item *newItem = new cat2(name);
            system[name] = newItem;
            //cout << i << " " << name << endl;
        }
        
        for (int i = 0; i < c; i++) {
            getline(in, name);
            item *newItem = new cat3(name);
            system[name] = newItem;
            //cout << i << " " << name << endl;
        }
        
        for (int i = 0; i < d; i++) {
            getline(in, name);
            if (!nextIter) {
                map<string, item *>::iterator current = system.find(name);
                if (current != system.end())
                    current->second->message();
            }
        }
        nextIter = false;
    }
    
    in.close();
    out.close();
    
    return 0;
}

/*
2
1 1 2 5
video card
wireless network
south bridge
cpu
video card
wireless network
wireless network
south bridge
cpu
0 0 1 11
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard
motherboard

 
 */


