#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;

  if (next_permutation(s.begin(), s.end())) {
    cout << s;
  } else {
    cout << "no answer";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}