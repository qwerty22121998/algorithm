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

const int MAXN = 4e6;

void init() {}

int _case = 0;

int n, m, a, b;

void sameM() {
  int cmM = min(a - n - 1, b - n - 1);
  cout << cmM << endl;
}

void solve() {
  _case++;

  cin >> n >> m >> a >> b;
  int res = 0;
  if (a < m + n || b < m + b || a > (m + n) * 1000 || b >= (m + n) * 100) {
    cout << "Case #" << _case << ": Impossible\n";
  }

  cout << "Case #" << _case << ": Possible\n";
  sameM();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  freopen("traffic_control_input.txt", "r", stdin);
  freopen("traffic_control_output.txt", "w", stdout);
  int T;
  cin >> T;
  init();
  while (T--) solve();
}