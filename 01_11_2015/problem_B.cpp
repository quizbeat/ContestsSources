#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long

int main() {
	ull n;
	cin >> n;
	set<ull> v;
	vector<ull> m;
	ull maxV = 0;
	ull a = 1;
	for (int i = 0; i < n; ++i) {
		ull d;
		cin >> d;
		if (d > maxV)
			maxV = d;
		v.insert(d);
		m.push_back(d);
	}
	bool f = 1;
	while (1) {
		++a;
		bool f = 1;
		for (int i = 0; i < n; ++i) {
			if (m[i] >= a && m[i]%a == 0) {
				f = 0;
				break;
			}
		}
		if (f) {
			break;
		}
	}
	while (1) {
		f = 1;
		for (ull x = 0; x < maxV+1; x += a) {
			if (v.find(x) != v.end()) {
				f = 0;
				break;
			}
		}
		if (f) {
			cout << a << endl;
			break;
		}
		while (1) {
			++a;
			bool f = 1;
			for (int i = 0; i < n; ++i) {
				if (m[i] >= a && m[i]%a == 0) {
					f = 0;
					break;
				}
			}
			if (f) {
				break;
			}
		}
	}
	return 0;
}