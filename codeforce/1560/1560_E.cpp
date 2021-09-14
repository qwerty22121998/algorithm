#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> t;

void init() {
  ll now = 1;

  for (int i = 0; i < 62; i++) {
    t.push_back(to_string(now));
    now *= 2;
  }
}

int op(string a, string b) {
  int res = 0;

  int j = 0;
  for (int i = 0; i < b.size(); i++) {
    bool ok = false;
    for (; j < a.size(); j++) {
      if (a[j] == b[i]) {
        res++;
        ok = true;
        j++;
        break;
      }
    }
    if (!ok) break;
  }

  return a.size() - res + b.size() - res;
}

void solve() {
  string a;
  cin >> a;
  int res = a.size() + 1;
  for (auto e : t) {
    res = min(res, op(a, e));
  }
  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  init();
  cin >> T;
  while (T--) solve();
}