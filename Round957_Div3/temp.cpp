/**
 *    author:  tourist
 *    created: 11.07.2024 23:45:00
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> res;
    for (int a = 1; a <= 10000; a++) {
      string s = to_string(n);
      int len = int(s.size());
      while (s.size() < 8) {
        s += s;
      }
      for (int b = a * len - 1; b >= a * len - 8; b--) {
        if (1 <= b && b <= 10000) {
          int w = a * len - b;
          string t = s.substr(0, w);
          if (stoi(t) == n * a - b) {
            res.emplace_back(a, b);
          }
        }
      }
    }
    cout << res.size() << '\n';
    for (auto it: res) {
      cout << it.first << " " << it.second << '\n';
    }
  }
  return 0;
}
