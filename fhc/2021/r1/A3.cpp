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
const ll MODULO = 1e9 + 7;

int _case = 0;

int n;
string s;
// ll f[MAXN + 10];
string sa;

string pairs[2] = {"XO", "OX"};
vector<int> f, g;

void init() {
  _case++;
  f.clear();
}

void solve() {
  init();
  cin >> n >> s;
  int now = s[0];
  int nowIdx = 0;
  f.push_back(0);
  g.push_back(0);
  ll factor = 1;
  for (int i = 1; i < s.size(); i++) {
    f.push_back(f.back());
    for (auto a : pairs) {
      if (s[i] == a[0]) {
        if (s[i - 1] == a[1] || s[i - 1] == 'F' && now == a[1]) {
          f[i] = (f[i - 1] + nowIdx * factor + factor) % MODULO;
        }
      }
    }
    if (s[i] != 'F' && s[i] != '.') {
      now = s[i];
      nowIdx = i;
    }
    if (s[i] == '.') {
      factor *= 2;
    }
    g.push_back((g.back() * factor + f[i] * factor) % MODULO);
  }
  // ll res = 0;
  // for (auto e : f) res = (res + e) % MODULO;
  for (auto e : f) cout << e << " ";
  cout << endl;
  cout << "Case #" << _case << ": " << g.back() << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("weak_typing_chapter_3_input.txt", "r", stdin);
  freopen("weak_typing_chapter_3_output.txt", "w", stdout);
  int T;
  cin >> T;
  while (T--) solve();
}