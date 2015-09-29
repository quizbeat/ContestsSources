#include <iostream>
#include <vector>
using namespace std;
#define ll long long
class Point {
public:
	ll x, y, z;
	Point() {}
	Point(ll a, ll b, ll c) {
		x = a;
		y = b;
		z = c;
	}
	void setPoints(ll a, ll b, ll c) {
		x = a;
		y = b;
		z = c;
	}
	bool eql(ll a, ll b, ll c) {
		return a == x && b == y && c == z;
	}
};
int main() {
	ll a, b, c, n;
	cin >> a >> b >> c >> n;
	vector<Point> points(n);
	ll square = 2*(a*b + b*c + a*c);
	for (int i = 0; i < n; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		points[i].setPoints(x, y, z);
		ll s = 0;
		if (x == 0)
			++s;
		if (x == a-1)
			++s;

		if (y == 0)
			++s;
		if (y == b-1)
			++s;

		if (z == 0)
			++s;
		if (z == c-1)
			++s;
		ll p = 0;
		for (int j = 0; j < i; ++j) {
			if (points[j].eql(x-1, y, z)) ++p;
			if (points[j].eql(x+1, y, z)) ++p;
			if (points[j].eql(x, y-1, z)) ++p;
			if (points[j].eql(x, y+1, z)) ++p;
			if (points[j].eql(x, y, z-1)) ++p;
			if (points[j].eql(x, y, z+1)) ++p;
		}
		square += 6-2*(s+p);
	}
	cout << square << "\n";
	return 0;
}