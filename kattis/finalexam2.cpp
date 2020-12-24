#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;

int n;
vector<string> a;

void solve() {
  int res = 0;
  for (int i = 1; i < a.size(); i++) {
    res += a[i] == a[i - 1];
  }
  cout << res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &e : a) cin >> e;
  solve();
}