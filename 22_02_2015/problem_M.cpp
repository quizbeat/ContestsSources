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

struct Point{
    int x, y;
};

int check(char map[3][3]) {
    int winner = 2;
    for (int i=0; i<3; ++i) {
        bool oFH = 1, xFH = 1, oFV = 1, xFV = 1;
        for (int j=0; j<3; ++j) {
            if (map[i][j] != 'o') {
                oFH = 0;
            }
            if (map[i][j] != 'x') {
                xFH = 0;
            }
            if (map[j][i] != 'o') {
                oFV = 0;
            }
            if (map[j][i] != 'x') {
                xFV = 0;
            }
        }
        if (oFH || oFV) {
            winner = 1;
        }
        else if (xFH || xFV) {
            winner = 0;
        }
    }
    bool oFD1 = 1, xFD1 = 1, oFD2 = 1, xFD2 = 1;
    for (int i=0; i<3; ++i) {
        if (map[i][i] != 'o') {
            oFD1 = 0;
        }
        if (map[i][i] != 'x') {
            xFD1 = 0;
        }
        if (map[i][2-i] != 'o') {
            oFD2 = 0;
        }
        if (map[i][2-i] != 'x') {
            xFD2 = 0;
        }
    }

    if (oFD1 || oFD2) {
        winner = 1;
    }
    else if (xFD1 || xFD2) {
        winner = 0;
    }
    return winner;
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    Point freeCell[2];
    int n = 0;
    int xN = 0, oN = 0;
    char map[3][3];
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            map[i][j] = in.get();
            if (map[i][j] == '.') {
                freeCell[n].x = j;
                freeCell[n].y = i;
                ++n;
            }
            if (map[i][j] == 'x') {
                ++xN;
            }
            else if (map[i][j] == 'o') {
                ++oN;
            }
        }
        in.get();
    }
    char firstPlayer, secondPlayer;
    if (oN < xN) {
        firstPlayer = 'o';
        secondPlayer = 'x';
    }
    else {
        firstPlayer = 'x';
        secondPlayer = 'o';
    }
    map[freeCell[0].y][freeCell[0].x] = firstPlayer;
    int winner = check(map);
    float pX = 0, pO = 0;
    if (firstPlayer == 'o' && winner == 1 || firstPlayer == 'x' && winner == 0) {
        pO += 1;
    }
    else {
        map[freeCell[1].y][freeCell[1].x] = secondPlayer;
        winner = check(map);
        if (firstPlayer == 'o' && winner == 0 || firstPlayer == 'x' && winner == 1) {
            pX += 1;
        }
    }

    map[freeCell[0].y][freeCell[0].x] = '.';
    map[freeCell[1].y][freeCell[1].x] = firstPlayer;
    winner = check(map);
    if (firstPlayer == 'o' && winner == 1 || firstPlayer == 'x' && winner == 0) {
        pO += 1;
    }
    else {
        map[freeCell[0].y][freeCell[0].x] = secondPlayer;
        winner = check(map);
        if (firstPlayer == 'o' && winner == 0 || firstPlayer == 'x' && winner == 1) {
            pX += 1;
        }
    }

    if (pO > pX) {
        if (firstPlayer == 'o')
            out << "o";
        else
            out << "x";
    }
    else if (pO < pX) {
        if (secondPlayer == 'x')
            out << "x";
        else
            out << "o";
    }
    else {
        out << "tie";
    }
    //cout << "\npX = " << pX << " pO = " << pO << endl;
    in.close();
    out.close();
    return 0;
}
/*
xo.
oxo
xx.
*/
