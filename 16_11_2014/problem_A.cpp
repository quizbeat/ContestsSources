#include <iostream>
#include <fstream>
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
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.00001
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}


int main()
{
    ll n, m;
    ll a, b, d;
    cin >> n >> m;
    vector< pair<ll, ll> > maxA(m, make_pair(-1, -1)), minB(m, make_pair(-1, -1));
    for (ll i=0; i<n; ++i) {
        cin >> a >> b >> d;
        --d;
        if (maxA[d].second == -1 || maxA[d].second < a) {
            maxA[d].second = a;
            maxA[d].first = i;
        }
        if (minB[d].second == -1 || minB[d].second > b) {
            minB[d].second = b;
            minB[d].first = i;
        }
    }
    for (ll i=0; i<m; ++i) {
        if (minB[i].second < maxA[i].second) {
            cout << "TAK " << minB[i].first+1 << ' ' << maxA[i].first+1 << '\n';
        }
        else {
            cout << "NIE\n";
        }
    }
    return 0;
}
