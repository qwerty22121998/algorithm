#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int e;
  for (int i = 0; i < n; i++) {
    cin >> e;
    cout << n + 2 - e << " ";
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}