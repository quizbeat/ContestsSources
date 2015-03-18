#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <list>
#include <iterator>
#include <climits>
using namespace std;
#define ll long long
#define ull unsigned long long
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}
int main()
{
    ll T;
    cin >> T;
    cin.get();
    while (T--) {
        vector<bool> nums(10, 0);
        char c;
        while((c=cin.get())!='\n' && !cin.eof())
        {
            if(cin.eof())
                break;
            nums[c-'0'] = 1;
        }
        bool f = 0;
        for(ll i=0; i<10; ++i)
        {
            if(!nums[i])
            {
                f = 1;
                cout << i;
            }
        }
        if(!f)
            cout << "allo";
        cout << '\n';
            
    }
    return 0;
}