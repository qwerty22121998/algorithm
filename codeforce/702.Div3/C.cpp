#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll e) {
  for (ll i = 1; i <= cbrt(e) + 1; i++) {
    ll bbb = e - i * i * i;
    double b = cbrt(bbb);
    if (b == round(b) && b >= 1) return true;
  }
  return false;
}

void solve() {
  ll x;
  cin >> x;
  cout << (check(x) ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}