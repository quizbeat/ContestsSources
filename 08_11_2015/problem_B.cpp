#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

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

int main() {

	int temp;
	ULL N, M;
	cin >> N >> M;
	if(N == M) {
		cout << 6 << endl;
		return 0;
	}
	else {
		ULL answ = 3;
		for(int i = 0; i < myAbs(N, M); i++) {
			answ *= 2;
		}
		cout << answ << endl;
	}

	//cin >> temp;
	
	return 0;

}