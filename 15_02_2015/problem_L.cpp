#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.00001
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}

int main()
{
    ifstream in("maze.in");
    //ofstream out("maze.out");

    long T;
    in >> T;
    in.get();
    while (T--) {

        char map[210][210];
        for (ll i=0; i<210; ++i) {
            for (ll j=0; j<210; ++j) {
                map[i][j] = 'X';
            }
        }
        ll maxX = 0, maxY = 0, minX = 0, minY = 0, x = 0, y = 0;
        int dir = 0;
        char c;
        while((c = in.get()) != '\n') {
            if (c == 'B') {
                if (dir == 0) dir = 2;
                else if (dir == 1) dir = 3;
                else if (dir == 2) dir = 0;
                else if (dir == 3) dir = 1;
            }
            else if (c == 'R') {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 2;
            }
            else if (c == 'L') {
                if (dir == 0) dir = 1;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 3;
                else if (dir == 3) dir = 0;
            }
            map[x+105][y+105] = '.';
            if (dir == 0) ++x;
            else if (dir == 1) --y;
            else if (dir == 2) --x;
            else ++y;
            if (x > maxX) maxX = x;
            else if(x < minX) minX = x;
            if (y > maxY) maxY = y;
            else if(y < minY) minY = y;
        }
        cout << maxY - minY + 3 << ' ' << maxX - minX + 2 << '\n';
        for (ll i=minY-1; i<maxY+2; ++i) {
            for (ll j=minX; j<maxX+2; ++j) {
                cout.put(map[j+105][i+105]);
            }
            cout.put('\n');
        }
    }

    in.close();
    //out.close();
    return 0;
}
/*
 3
 FFRBLF
 FFRFRBRFBFRBRFLF
 FRLFFFLBRFFFRFFFRFRFBRFLBRFRLFLFFR
*/
