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

int n;
string s;
ll f[MAXN + 10][2];

void solve() {
  _case++;
  cin >> n >> s;

  switch (s[0]) {
    case 'X':
      f[0][0] = 0;
      f[0][1] = INT_MAX;
      break;
    case 'O':
      f[0][0] = INT_MAX;
      f[0][1] = 0;
      break;
    case 'F':
      f[0][0] = f[0][1] = 0;
  }

  for (int i = 1; i < n; i++) {
    if (s[i] == 'F') {
      f[i][0] = min(f[i - 1][0], f[i - 1][1] + 1);
      f[i][1] = min(f[i - 1][1], f[i - 1][0] + 1);
    }
    if (s[i] == 'X') {
      f[i][1] = INT_MAX;
      f[i][0] = min(f[i - 1][0], f[i - 1][1] + 1);
    }
    if (s[i] == 'O') {
      f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1]);
      f[i][0] = INT_MAX;
    }
  }

  cout << "Case #" << _case << ": " << min(f[n - 1][0], f[n - 1][1]) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  freopen("weak_typing_chapter_1_input.txt", "r", stdin);
  freopen("weak_typing_chapter_1_output.txt", "w", stdout);
  int T;
  cin >> T;
  init();
  while (T--) solve();
}