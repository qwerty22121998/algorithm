#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a;
  cin >> a;
  int l = sqrt(a);
  if (l * l == a) {
    cout << l << " " << 1 << "\n";
    return;
  }
  int r = l + 1;
  int l2 = l * l;
  int r2 = r * r;
  int mid = (l2 + r2 + 1) / 2;

  int row = a - l2;

  int col = r;
  if (row > r) {
    col -= (row - r);
    row = r;
  }
  cout << row << " " << col << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}