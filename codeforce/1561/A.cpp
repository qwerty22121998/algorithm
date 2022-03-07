#include <bits/stdc++.h>
using namespace std;

int isSorted(const vector<int>& a) {
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] > a[i + 1]) return false;
  }
  return true;
}

vector<int> a;

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  for (auto& e : a) cin >> e;
  int now = 0;
  while (!isSorted(a)) {
    for (int i = now % 2; i < n - 1; i += 2) {
      if (a[i] > a[i + 1]) {
        swap(a[i], a[i + 1]);
      }
    }
    now++;
  }
  cout << now << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("a.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
}