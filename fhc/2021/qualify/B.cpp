#include <bits/stdc++.h>

using namespace std;

#define x first

#define y second

#define printArr(arr)                                         \
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << " "; \
  cout << endl;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<llll> vll;
typedef map<int, int> mii;

int n;
vector<string> c;
vector<int> h;
vector<int> v;
void init() {
  h.assign(n, 0);
  v.assign(n, 0);
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[i].size(); j++) {
      if (c[i][j] == 'X') {
        if (h[i] != -1) {
          h[i]++;
        }
        if (v[j] != -1) {
          v[j]++;
        }
      }
      if (c[i][j] == 'O') {
        h[i] = v[j] = -1;
      }
    }
  }
}

int _case = 0;

void solve() {
  _case++;
  cin >> n;
  c.resize(n);
  for (auto &arr : c) {
    cin >> arr;
  }
  init();
  int res = INT_MAX;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool oh, ov;
    oh = ov = false;
    // h
    int hc;
    if (h[i] != -1) {
      oh = true;
      hc = n - h[i];
      if (hc < res) {
        res = hc;
        cnt = 0;
      }
      if (hc == res) cnt++;
    }

    // v
    int vc;
    if (v[i] != -1) {
      ov = true;
      vc = n - v[i];
      if (vc < res) {
        res = vc;
        cnt = 0;
      }
      if (vc == res) cnt++;
    }

    if (oh && ov) {
      if (hc == res && vc == res && res == 1 && c[i][i] == '.') {
        cnt--;
      }
    }
  }
  cout << "Case #" << _case << ": ";
  if (cnt == 0) {
    cout << "Impossible\n";
  } else {
    cout << res << ' ' << cnt << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("xs_and_os_input.txt", "r", stdin);
  freopen("xs_and_os_output.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--) solve();
}