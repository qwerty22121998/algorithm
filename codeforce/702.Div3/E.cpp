#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> ii;
int n;
vector<ii> a;
unordered_map<int, int> mp;
vector<ll> f;

void solve() {
  cin >> n;
  a.clear();
  mp.clear();
  a.resize(n);
  f.clear();
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  for (auto e : a) {
    if (f.empty())
      f.push_back(e.first);
    else
      f.push_back(f.back() + e.first);
  }
  //   for (auto e : a) cout << e.first << " " << e.second << endl;
  mp[a.back().second] = 1;
  for (int i = a.size() - 2; i > 0; i--) {
    if (f[i] < a[i + 1].first && a[i].second != a[i + 1].second) break;
    mp[a[i].second] = 1;
  }
  if (a.size() > 1) {
    if (a[0].first == a[1].first && mp[a[1].second]) mp[a[0].second] = 1;
  }
  int res = 0;
  for (int i = 0; i <= a.size(); i++) {
    if (mp[i]) res++;
  }
  cout << res << "\n";
  for (int i = 0; i <= a.size(); i++) {
    if (mp[i]) cout << i << " ";
  }
  cout << "\n";
}
int main() {
  //   freopen("i.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) solve();
}