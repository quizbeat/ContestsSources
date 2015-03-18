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

vector < vector<char> > paths;
vector<char> path;
size_t __min;

void foo(char map[4][4], int x, int y) {
    if (x == 3 && y == 3) {
        if (path.size() < __min) {
            __min = path.size();
        }
        paths.push_back(path);
    }
    if (x<3 && map[y][x+1] == '.') {
        path.push_back('R');
        map[y][x] = 'X';
        foo(map, x+1, y);
        map[y][x] = '.';
        path.pop_back();
    }
    if (x>0 && map[y][x-1] == '.') {
        path.push_back('L');
        map[y][x] = 'X';
        foo(map, x-1, y);
        map[y][x] = '.';
        path.pop_back();
    }
    map[y][x] = '.';
    if (y<3 && map[y+1][x] == '.') {
        path.push_back('D');
        map[y][x] = 'X';
        foo(map, x, y+1);
        map[y][x] = '.';
        path.pop_back();
    }
    map[y][x] = '.';
    if (y>0 && map[y-1][x] == '.') {
        path.push_back('U');
        map[y][x] = 'X';
        foo(map, x, y-1);
        map[y][x] = '.';
        path.pop_back();
    }
}

int main()
{
    char map[4][4];
    bool e = 1;
    while (e) {
        for (int i=0; i<4; ++i) {
            for (int j=0; j<4; ++j) {
                map[i][j] = cin.get();
            }
            cin.get();
        }
        __min = 100500;
        foo(map, 0, 0);
        bool f = 0;
        for (int i=0; i<paths.size(); ++i) {
            if (paths[i].size() != __min) {
                for (int j=0; j<paths[i].size(); ++j) {
                    cout.put(paths[i][j]);
                }
                f = 1;
                break;
            }
        }
        if (!f) {
            cout << -1;
        }
        cout.put('\n');
        for (int i=0; i<5; ++i) {
            cin.get();
            if (cin.eof()) {
                e = 0;
                break;
            }
        }
        paths.clear();
        path.clear();
    }
    return 0;
}
