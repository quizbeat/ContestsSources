#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.00001
ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}

int main()
{
    ifstream in("lesson.in");
    //ofstream out("maze.out");

    long T;
    in >> T;
    in.get();
    const string names[] = {"Sail", "Frigate", "Cruiser", "Dreadnought"};
    while (T--) {
        ll n;
        in >> n;
        in.get();
        char mapA[10][10], mapB[10][10];
        vector< pair<int, int> > A(4, make_pair(0, 0)), B(4, make_pair(0, 0));
        for(ll i=0; i<n; ++i) {
            for (ll j=0; j<n; ++j) {
                mapA[i][j] = in.get();
                if (mapA[i][j] != '.')
                    ++A[mapA[i][j]-'0'-1].first;
            }
            in.get();
        }
        for(ll i=0; i<n; ++i) {
            for (ll j=0; j<n; ++j) {
                mapB[i][j] = in.get();
                if (mapB[i][j] != '.')
                    ++B[mapB[i][j]-'0'-1].first;
            }
            in.get();
        }
        vector< pair<ll, ll> > movesA(n*n), movesB(n*n);
        for (ll i=0; i<n*n; ++i) {
            ll x, y;
            in >> y >> x;
            movesA[i] = make_pair(y - 1, x - 1);
        }
        for (ll i=0; i<n*n; ++i) {
            ll x, y;
            in >> y >> x;
            movesB[i] = make_pair(y - 1, x - 1);
        }
        ll shipsA = 4, shipsB = 4;
        bool win = 0;
        for (ll moveA = 0, moveB = 0; moveA < n*n && moveB < n*n && !win;) {
            ll y, x;
            bool f = 1;
            while (f) {
                f = 0;
                x = movesA[moveA].second;
                y = movesA[moveA].first;
                ++moveA;
                if (mapB[y][x] != '.') {
                    ++B[mapB[y][x]-'0'-1].second;
                    if (B[mapB[y][x]-'0'-1].second == B[mapB[y][x]-'0'-1].first) {
                        cout << "Alice sank Bob's " << names[B[mapB[y][x]-'0'-1].first-1] << '\n';
                        f = 1;
                        --shipsB;
                        if (!shipsB) {
                            cout << "Alice\n";
                            win = 1;
                            break;
                        }
                    }
                }
            }
            if (win) {
                break;
            }
            f = 1;
            while (f) {
                f = 0;
                x = movesB[moveB].second;
                y = movesB[moveB].first;
                ++moveB;
                if (mapA[y][x] != '.') {
                    ++A[mapA[y][x]-'0'-1].second;
                    if (A[mapA[y][x]-'0'-1].second == A[mapA[y][x]-'0'-1].first) {
                        cout << "Bob sank Alice's " << names[A[mapA[y][x]-'0'-1].first-1] << '\n';
                        f = 1;
                        --shipsA;
                        if (!shipsA) {
                            cout << "Bob\n";
                            win = 1;
                            break;
                        }
                    }
                }
            }
            if (win) {
                break;
            }
        }
    }

    in.close();
    //out.close();
    return 0;
}
