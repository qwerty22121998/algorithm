#include <bits/stdc++.h>
using namespace std;

int f[3] = {0};

int solve(int a, int b, int c) {
  int m = (a + b + c) / 3;
  if (a == b && b == c) return 0;
  int res = 0;
  int addA = 0, addB = 0, addC = 0;
  if (a > m) {
    res += a - m;
    addB += a - m;
    a = m;
  }
  if (b > m) {
    res += b - m;
    addC += b - m;
    b = m;
  }
  if (c > m) {
    res += c - m;
    addA += c - m;
    c = m;
  };
  return res + solve(a + addA, b + addB, c + addC);
}

void solve() {
  memset(f, 0, sizeof(f));
  int n;

  cin >> n;
  int total = 0;

  while (n--) {
    int e;
    cin >> e;
    f[e % 3]++;
    total += e % 3;
  }

  cout << solve(f[0], f[1], f[2]) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;

  while (T--) solve();
}