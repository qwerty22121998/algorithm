#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;

const ll MAXN = 1e3;

int xres[10000];

void init() {
  xres[0] = 0;
  for (int i = 0; i <= MAXN; i++) {
    xres[i] = xres[i - 1] ^ i;
  }
}

void solve() {
  int m;
  cin >> m;
  int exclude = xres[m] ^ m;
  int maxx = m;
  m -= exclude != 0;
  cout << m << "\n";
  for (int i = 1; i <= maxx; i++) {
    if (i == exclude) continue;
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int T;
  cin >> T;
  while (T--) solve();
}