#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m;

const ll MAXN = 2e5 + 10;
ll f[MAXN] = {0};
ll sum[MAXN] = {0};

void solve() {
  f[0] = 0;
  sum[0] = 0;
  f[1] = 1;
  sum[1] = 1;
  f[2] = 2;
  sum[2] = sum[1] + f[2];
  for (int i = 3; i <= n; i++) {
    cout << "i = " << i << endl;
    int pos = i;
    f[i] = sum[i - 1] % m;
    for (int j = 2; j <= i; j++) {
      cout << " i + " << i / j << endl;
      f[i] = (f[i] + f[i / j]) % m;
    }
    sum[i] = sum[i - 1] + f[i];
    sum[i] %= m;
  }

  for (int i = 0; i <= n; i++) cout << f[i] << " ";
  cout << endl;
  cout << f[n] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  freopen("a.in", "r", stdin);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  solve();
}