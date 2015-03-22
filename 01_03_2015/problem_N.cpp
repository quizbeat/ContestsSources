//#include <iostream>
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
#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.00001
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}

int main()
{
    int T;
    cin >> T;
    cin.get();
    while (T--) {
        ull a = 0;
        char c;
        while ((c=cin.get())!='\n') {
            a <<= 1;
            if (c == 'B') {
                a |= 1;
            }
        }
        cout << a << '\n';
    }
    return 0;
}
