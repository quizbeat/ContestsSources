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
#include <string>

#include <sstream>
#include <fstream>

#define LL  long long
#define ULL unsigned long long
#define EPS 1e-11
#define inf (1LL << 31) - 1
#define nl cout<<'\n'

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))

#define VI vector<int>
#define VS vector<string>
#define VC vector<char>

#define ASCII_code_A 65
#define ASCII_code_Z 90
#define ASCII_code_a 97
#define ASCII_code_z 122
#define ASCII_code_0 48
#define ASCII_code_9 57

#define more_speed ios_base::sync_with_stdio(false);

using namespace std;

// check for prime
bool prime(ULL n) {
    for (ULL i = 2; i <= (ULL)sqrt(double(n)); i++)
        if (n % i == 0)
            return false;
    return true;
}

// comparators
bool cmpPairAscendingByFirst(const pair<LL, LL> & a, const pair<LL, LL> & b) {
    return a.first < b.first;
}

bool cmpPairDescendingByFirst(const pair<LL, LL> & a, const pair<LL, LL> & b) {
    return a.first > b.first;
}

bool cmpPairAscendingBySecond(const pair<LL, LL> & a, const pair<LL, LL> & b) {
    return a.second < b.second;
}

bool cmpPairDescendingBySecond(const pair<LL, LL> & a, const pair<LL, LL> & b) {
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

LL problemID(string s) {
    return s[0] - 'A' + 1;
}

double distance(double a1, double a2) {
	double d = 0;
	if(a1 >= 0 && a2 >= 0) {
		if(a1 > a2)
			d = a1 - a2;
		else
			d = a2 - a1;
	} else {
		if(a1 < 0 && a2 < 0) {		
			if(a1 > a2)
				d = a1 - a2;
			else
				d = a2 - a1;
		} else {
			a1 = abs(a1);
			a2 = abs(a2);
			d = a1 + a2;
		}
	}
	return d;
}


ULL gcd (ULL a, ULL b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}


int main() {

    more_speed

    // for testing
    //ifstream in("/Users/air/Documents/dev/contest/contest/in");
    //ofstream out("/Users/air/Documents/dev/contest/contest/out");

    // for submit
    //ifstream in("input.txt");
    //ofstream out("output.txt");

	ULL n;
	cin >> n;

	vector <ULL> v1(n);
	vector <ULL> v2(n);
    cin.get();
	for (ULL i = 0; i < n; i++) {
        ULL a = 0;
        char c;
        while((c=cin.get())!='\n') {
            a = a*26+(c-'A');
        }
		v1[i] = a;
	}

	for (ULL i = 0; i < n; i++) {
        ULL a = 0;
        char c;
        while((c=cin.get())!='\n') {
            a = a*26+(c-'A');
        }
        v2[i] = a;
	}
	
	ULL count = 0;
	ULL sum1 = 0;
	ULL sum2 = 0;

	for(ULL i = 0; i < n; i++) {
		if(v1[i] == v2[i] && count == 0) {
			cout << "1" << endl;
			continue;
		}
		else {
			sum1 += v1[i];
			sum2 += v2[i];
			count++;
		}
		
		if(sum1 == sum2) {
			cout << count << endl;
			count = 0;
			sum1 = 0;
			sum2 = 0;
		}
	}

    //in.close();
    //out.close();

    return 0;
}
