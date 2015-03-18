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
int main()
{
    ll n;
    //char vars[26][1000];
    //vector<int> varCount(26, 0);
    vector < stack< pair<ll, int> > > vars(26);
    int scope = 0;
    cin >> n;
    char str[20];
    for (int i=0; i<n; ++i) {
        cin >> str;
        if(str[0] == '{') {
            ++scope;
        }
        else if(str[0] == '}') {
            for (int i=0; i<26; ++i) {
                if(!vars[i].empty() && vars[i].top().second == scope) {
                    vars[i].pop();
                }
            }
            --scope;
        }
        else if(str[1] == '=') {
            int c1 = str[0]-'a';
            ll a;
            if(isalpha(str[2])) {
                int c2 = str[2]-'a';
                a = vars[c2].top().first;
                int c1Scope = vars[c1].top().second;
                vars[c1].pop();
                vars[c1].push(make_pair(a, c1Scope));
            }
            else {
                a = 0;
                for (int i=2; str[i]!='\0'; ++i)
                    a = a*10+str[i]-'0';
            }
            int c1Scope = vars[c1].top().second;
            vars[c1].pop();
            vars[c1].push(make_pair(a, c1Scope));
        }
        else if(!strcmp(str, "int")) {
            cin >> str;
            int c;
            c = str[0]-'a';
            vars[c].push(make_pair(-1, scope));
        }
        else if(!strcmp(str, "print")) {
            cin >> str;
            int c = str[0]-'a';
            cout << vars[c].top().first << '\n';
        }
    }
    return 0;
}