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

ll f['Z' + 1]['Z' + 1];

void init() {
  for (int a = 'A'; a <= 'Z'; a++) {
    for (int b = 'A'; b <= 'Z'; b++) {
      f[a][b] = INT_MAX;
    }
    f[a][a] = 0;
  }
}

string s;

ll solve(char c) {
  ll step = 0;
  for (auto e : s) {
    if (e == c) continue;
    if (f[e][c] == INT_MAX) {
      return INT_MAX;
    }
    step += f[e][c];
  }
  return step;
}

void floyd() {
  for (int k = 'A'; k <= 'Z'; k++) {
    for (int a = 'A'; a <= 'Z'; a++) {
      for (int b = 'A'; b <= 'Z'; b++) {
        if (f[a][k] != INT_MAX && f[k][b] != INT_MAX)
          f[a][b] = min(f[a][b], f[a][k] + f[k][b]);
      }
    }
  }
}

int _case = 0;

void solve() {
  init();
  _case++;
  cin >> s;
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string e;
    cin >> e;
    f[e[0]][e[1]] = 1;
  }
  floyd();
  ll res = INT_MAX;
  for (int a = 'A'; a <= 'Z'; a++) res = min(res, solve(a));
  cout << "Case #" << _case << ": ";
  if (res == INT_MAX) {
    cout << "-1\n";
  } else {
    cout << res << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("consistency_chapter_2_input.txt", "r", stdin);
  freopen("consistency_chapter_2_output.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--) solve();
}