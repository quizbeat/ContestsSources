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

int main()
{
    long T;
    cin >> T;
    char aStr[100], bStr[100];
    cin.get();
    while (T--) {
        char c;
        long a = 0, aN = 0, bN = 0, res = 0;
        while (c = cin.get()) {
            if (c == ' ' || c == '\n') {
                if (a&1) {
                    if (!strcmp("u", bStr) || !strcmp("ur", bStr) || strstr(bStr, "lol") != NULL) {
                        ++res;
                    }
                    else if((!strcmp("would", aStr) || !strcmp("should", aStr)) && !strcmp("of", bStr)) {
                        ++res;
                    }
                    aN = 0;
                }
                else {
                    if (!strcmp("u", aStr) || !strcmp("ur", aStr) || strstr(aStr, "lol") != NULL) {
                        ++res;
                    }
                    else if(a && (!strcmp("would", bStr) || !strcmp("should", bStr)) && !strcmp("of", aStr)) {
                        ++res;
                    }
                    bN = 0;
                }
                if (c == '\n') {
                    break;
                }
                ++a;
                continue;
            }
            if (a&1) {
                bStr[bN++] = c;
                bStr[bN] = '\0';
            }
            else {
                aStr[aN++] = c;
                aStr[aN] = '\0';
            }
        }
        cout << res << '\n';
    }
    return 0;
}
