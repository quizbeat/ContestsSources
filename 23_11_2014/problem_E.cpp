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
using namespace std;
#define ll long long
#define ull unsigned long long
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}
void answer(ll n, ll l, ll r) {
    cout << n << " = " << l;
    for(ll i=l+1; i<=r; ++i) {
        cout << " + " << i;
    }
    cout.put('\n');
}
int main()
{
    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll t = n;
        bool f = 0;
        while(t!=0) {
            if (t>1 && t&1) {
                f = 1;
                break;
            }
            t >>= 1;
        }
        if(!f) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        f = 0;
        for (ll i=2; !f && i<100500; ++i) {
            ll sum = 0;
            ll r = n/i;
            ll l = r-i+1;
            if(l<1) {
                l = 1;
                r = l+i-1;
            }
            for(ll j=l; j<=r; ++j) {
                sum += j;
            }
            if(sum == n) {
                answer(n, l, r);
                break;
            }
            for(ll j=r+1; j<r+i; ++j) {
                sum += j-l;
                if(sum == n) {
                    answer(n, l+1, j);
                    f = 1;
                    break;
                }
                ++l;
            }
        }
    }
    return 0;
}