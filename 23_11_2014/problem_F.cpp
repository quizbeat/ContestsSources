#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <list>
#include <iterator>
#include <climits>
#include <stack>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.00001
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}

struct Gear {
    int x, y, r;
};

struct GearSpeed {
    ll n, d;
    bool dir;
};
int main()
{
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;

        vector< list<int> > m(n);
        vector<bool> u(n, 0);
        vector<Gear> gears(n);
        for (ll i=0; i<n; ++i) {
            cin >> gears[i].x >> gears[i].y >> gears[i].r;
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                double x = gears[i].x-gears[j].x;
                double y = gears[i].y-gears[j].y;
                if(sqrt(x*x+y*y)<=gears[i].r+gears[j].r) {
                    m[i].insert(m[i].begin(), j);
                    m[j].insert(m[j].begin(), i);
                }
            }
        }
        vector<GearSpeed> speed(n);
        speed[0].n = 1;
        speed[0].d = 1;
        speed[0].dir = 0;
        queue<int> q;
        q.push(0);
        u[0] = 1;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            list<int>::iterator it = m[a].begin();
            for (; it!=m[a].end(); ++it) {
                int b = *it;
                if(u[b])
                    continue;
                u[b] = 1;
                speed[b].n = speed[a].n * gears[a].r;
                speed[b].d = speed[a].d * gears[b].r;
                speed[b].dir = !speed[a].dir;
                ll u = speed[b].n;
                ll v = speed[b].d;
                ll temp;
                while (v != 0) {
                    temp = u % v;
                    u = v;
                    v = temp;
                }
                speed[b].n /= u;
                speed[b].d /= u;
                q.push(b);
            }
        }
        for (ll i=0; i<n; ++i) {
            if(!u[i])
                cout << "not moving\n";
            else {
                cout << speed[i].n;
                if(speed[i].d != 1) {
                    cout << '/' << speed[i].d;
                }
                cout.put(' ');
                if(speed[i].dir) {
                    cout << "counterclockwise\n";
                }
                else {
                    cout << "clockwise\n";
                }
            }
        }
    }
    return 0;
}
/*
1
5
0 0 6
6 8 4
-9 0 3
6 16 4
0 -11 4
*/