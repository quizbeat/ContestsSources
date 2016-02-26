#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> a(n);
  for (long i = 0; i < n; ++i) {
    long d;
    cin >> d;
    a[i] = d;
  }
  sort(a.begin(), a.end());
  set<long> h;
  long max_s = 1;
  for (long i = 0; i < n; ++i) {
    long j = n-1;
    while (j > i) {
      if (j-i <= 2 * max_s)
        break;
      long sum = a[i] + a[j];
      if (h.find(sum) != h.end()) {
        j -= 1;
        continue;
      }
      else {
        h.insert(sum);
      }
      long count = 1;
      long y = j-1;
      for (long k = i+1; k <= y; ++k) {
        bool f = false;
        long x = y;
        while (!f && x > k) {
          long sum_k = a[k] + a[x];
          if (sum_k == sum) {
            count += 1;
            y = x - 1;
            f = true;
          }
          else if (sum_k < sum) {
            break;
          }
          x -= 1;
        }
      }
      if (count > max_s) {
        max_s = count;
      }
      j -= 1;
    }
  }
  cout << max_s << '\n';
  return 0;
}
