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

typedef struct {
    string name;
    vector<LL> scores;
} fteam;

bool compareByTotalAccepted(const fteam &team1, const fteam &team2) {
    LL totalTeam1 = team1.scores[0] / 1000;
    LL totalTeam2 = team2.scores[0] / 1000;
    return totalTeam1 < totalTeam2;
}

bool compareByTotalTime(const fteam &team1, const fteam &team2) {
    return team1.scores[0] > team2.scores[0];
}


typedef struct {
    LL num;
    ULL cap;
    short low;
} server;

bool cmp_low(const server &a, const server &b) {
    return a.low > b.low;
}

bool cmp_cap(const server &a, const server &b) {
    if (a.cap == b.cap) return a.low > b.low;
    return a.cap > b.cap;
}

/*LL dist(LL a1, LL a2) {
	LL distance;
	if(a1 >= 0 && a2 >= 0)
		if(a1 > a2)
			distance = a1 - a2;
		else
			distance = a2 - a1;
	if(a1 < 0 && a2 < 0)		
		if(a1 > a2)
			distance = a1 - a2;
		else
			distance = a2 - a1;
	if(a1 * a2 < 0) {
		a1 = abs(a1);
		a2 = abs(a2);
		distance = a1 + a2;
	}
	return distance;
}
*/

/*int dist(int a1, int a2) {
	LL distance;		
	if(a1 > a2)
		distance = a1 - a2;
	else
		distance = a2 - a1;
	return distance;
}
*/





typedef struct {
	int x;
	int y;
	int r;
} wheel;

typedef struct {
	ULL p;
	ULL q;
	bool side;
} speed;


ULL gcd (ULL a, ULL b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

/*bool comp(const meeting &a, const meeting &b) {
	if(a.d == b.d)
		return a.a < b.a;
	return a.d < b.d;
}*/



int main() {
    
    more_speed
    ifstream in("mosaic.in");
    ofstream out("mosaic.out");
	
	int N, M;

	in >> M >> N;

	int answ;

	if(N < 3 || M < 3) {
		out << "0" << endl;
		return 0;
	}

	if((N - 2)*(M - 2) % 2 == 0)
		answ = (N - 2)*(M - 2) / 2;
	else
		answ = (N - 2)*(M - 2) / 2 + 1;

	out << answ << endl;

	int k = 2;
	for(int i = 2; i < M; i++) {
		for(int j = k; j < N; j+=2) {
			out << (i - 1)*N + j << " ";		
		}
		if(k == 2)
			k = 3;
		else k = 2;
	}

	//cin >> N;


    in.close();
    out.close();
    
    return 0;
}


