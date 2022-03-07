#include <bits/stdc++.h>
using namespace std;

int solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);

  int mid = b - (a - 1);
  int maxx = mid * 2 - 2;
  if (maxx - b + a != b - a) return -1;

  if (maxx < a || maxx < b || c > maxx) return -1;

  c += (b - a);

  if (c > maxx) c -= maxx;

  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) cout << solve() << "\n";
}