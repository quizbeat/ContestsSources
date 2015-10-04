#include <iostream>
#include <cinttypes>
using namespace std;
#define ll long long
#define ull unsigned long long

uint32_t dehash(uint32_t value) {
    uint32_t hash = value;
    hash = hash - (hash<<16);
    uint32_t t = hash;
	hash = (hash xor (hash >> 11)) & ~((1ULL<<10)-1);
	for (int i = 0; i < 1023; ++i) {
		if ((hash xor (hash >> 11)) == t) {
			break;
		}
		++hash;
	}
	ull h = hash;
	for (ull i = 0;; ++i) {
		if (((h|(i<<32)) % 9) == 0) {
			hash = (h|(i<<32))/9;
			break;
		}
	}
	t = hash;
	hash = (hash xor (hash >> 6)) & ~((1ULL<<20)-1);
	for (int i = 0; i < 1048575; ++i) {
		if ((hash xor (hash >> 6)) == t) {
			break;
		}
		++hash;
	}
	h = hash;
	for (ull i = 0;; ++i) {
		if (((h|(i<<32)) % 1025) == 0) {
			hash = (h|(i<<32))/1025;
			break;
		}
	}
    return hash;
}

int main() {
	uint32_t Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		ull d;
		cin >> d;
		cout << dehash(d) << "\n";
	}
	return 0;
}