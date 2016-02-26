#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <string>

#define LL long long
#define ULL  unsigned long long


using namespace std;

ULL myAbs(ULL a, ULL b) {
	if(a > b) {
		return a - b;
	} else {
		return b - a + 1;
	}
}


typedef struct {
	int first;
	int second;
	int d;
} dist;

bool comp(const dist &a, const dist &b) {
    return a.d > b.d;
}


int main() {

	int temp;
	
	int N, M;
	cin >> N >> M;

	vector <int> up(N, 0);
	int cur, prev;
	cin >> prev;
	int k = 0;

	for(int i = 1; i < N; i++) {
		cin >> cur;
		if(cur > prev) {
			up[i] = k;
		}
		else {
			k++;
			up[i] = k;
		}
		prev = cur;
	}

	int l, r;
	for(int i = 0; i < M; i++) {
		cin >> l >> r;
		if(up[l-1] == up[r-1] && l != r) {
			cout << "Y";
		}
		else {
			cout << "N";
		}
	}

	//cin >> temp;
	
	return 0;

}