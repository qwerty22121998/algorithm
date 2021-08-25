#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

int calc(int a, int b) {
  if (a > b) swap(a, b);
  int res = 0;
  while (a * 2 < b) {
    res++;
    a *= 2;
  }
  return res;
}

void solve() {
  a.clear();
  cin >> n;
  a.resize(n);
  for (auto &e : a) cin >> e;
  int res = 0;
  for (int i = 1; i < a.size(); i++) {
    res += calc(a[i], a[i - 1]);
  }
  cout << res << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}