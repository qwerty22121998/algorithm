#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;
const ll MODULO = 1e9 + 9;

ll f[MAXN + 10];

void init() {
  memset(f, 0, sizeof(f));
  f[2] = 1;
  f[3] = 1;
  for (int i = 4; i <= MAXN; i++) f[i] = (f[i - 2] + f[i - 3]) % MODULO;
}

void solve() {
  int x;
  cin >> x;
  cout << f[x] << endl;
}
int main() {
  init();
  int T;
  cin >> T;
  while (T--) solve();
}