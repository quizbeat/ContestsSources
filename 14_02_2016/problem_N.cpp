#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define ll long long
#define ull unsigned long long
#define eps 0.0000000001
struct Gear {
  ll x, y, r;
  bool f;
  char sign;
  ll a, b;
  vector<ll> list;
  ll parent;
  Gear(ll a, ll b, ll c) {
    x = a;
    y = b;
    r = c;
    f = 0;
  }
};

double eq_eps(double a, double b) {
  return fabs(a - b) < eps;
}

int main() {
  ll n;
  cin >> n;
  vector<Gear *> v(n);
  for (int i = 0; i < n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    v[i] = new Gear(a, b, c);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      bool res = eq_eps(sqrt(pow(v[i]->x - v[j]->x, 2) + pow(v[i]->y - v[j]->y, 2)), v[i]->r + v[j]->r);
      if (res) {
        v[i]->list.push_back(j);
        v[j]->list.push_back(i);
      }

    }
  }
  ll x = 0;
  v[x]->a = 1;
  v[x]->b = 1;
  v[x]->sign = 1;
  queue<ll> qu;
  qu.push(x);
  while (!qu.empty()) {
    x = qu.front();
    qu.pop();
    Gear * cur_gear = v[x];
    for (ll i = 0; i < cur_gear->list.size(); ++i) {
      if (cur_gear->list[i] == cur_gear->parent)
        continue;
      Gear * next_gear = v[cur_gear->list[i]];
      if (!next_gear->f) {
        qu.push(cur_gear->list[i]);
        next_gear->f = 1;
        next_gear->parent = x;
      }
      else {
        cout << -1 << endl;
        return 0;
      }
      next_gear->sign = cur_gear->sign * -1;
      ll new_a, new_b, a, b;
      a = new_a = cur_gear->r * cur_gear->a;
      b = new_b = next_gear->r * cur_gear->b;
      while (b != 0) {
          ll r = a%b;
          a = b; b = r;
      }
      next_gear->a = new_a/a;
      next_gear->b = new_b/a;
    }
  }
  Gear * last_gear = v[n-1];
  if (last_gear->f == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll a = last_gear->a;
  ll b = last_gear->b;
  while (b != 0) {
      ll r = a%b;
      a = b; b = r;
  }
  cout << last_gear->b/a << ' ' << last_gear->sign * last_gear->a/a << endl;

  return 0;
}
