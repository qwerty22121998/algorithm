#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int n;
vector<vector<int> > a;
vector<ii> req;
void solve() {
  cin >> n;
  a.resize(n);
  req.resize(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    a[i].resize(m);
    int maxx = 0;
    int minn = INT_MAX;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      maxx = max(maxx, a[i][j] - j);
    }
    req[i].first = maxx;
    req[i].second = m;
  }
  // for (auto e : req) cout << e.first << " " << e.second << endl;

  sort(req.begin(), req.end());
  int res = req[0].first + 1;
  int now = res + req[0].second;

  for (int i = 1; i < req.size(); i++) {
    if (now <= req[i].first) {
      int diff = (req[i].first - now) + 1;
      now += diff;
      res += diff;
    }
    now += req[i].second;
  }
  cout << res << "\n";
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