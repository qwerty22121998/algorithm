#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector<int> a;

int res;
void calc(ii total, int index) {
  if (index == a.size()) {
    res = min(res, max(total.first, total.second));
    return;
  }
  calc(ii(total.first, total.second + a[index]), index + 1);
  calc(ii(total.first + a[index], total.second), index + 1);
}

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  res = 0;
  for (int &e : a) {
    cin >> e;
    res += e;
  }
  calc(ii(0, 0), 0);
  cout << res << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}