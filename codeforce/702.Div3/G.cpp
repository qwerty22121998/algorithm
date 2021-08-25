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

const int MAXPRIME = 1e6 + 1;
ll pdiv[MAXPRIME] = {0};
vl prime;

void eratos() {
  for (int i = 0; i < MAXPRIME; i++) pdiv[i] = i;
  pdiv[1] = 0;
  for (ll i = 2; i <= sqrt(MAXPRIME); i++) {
    if (pdiv[i] != i) continue;
    prime.push_back(i);
    ll j = i * i;
    while (j < MAXPRIME) {
      pdiv[j] = i;
      j += i;
    }
  }
}

void init() {}

vl a;
vl x;
vl f;

void solve() {
  ll m, n;
  cin >> n >> m;
  a.resize(n);
  f.resize(n);
  x.resize(m);
  for (auto &e : a) cin >> e;
  for (auto &e : x) cin >> e;
  f[0] = a[0];
  ll maxf = f[0];

  for (int i = 1; i < f.size(); i++) {
    f[i] = a[i] + f[i - 1];
    maxf = max(maxf, f[i]);
  }

  vll fs;
  vl pos;

  fs.push_back(llll(f[0], 0));

  for (int i = 1; i < f.size(); i++) {
    if (fs.back().x > f[i]) continue;
    fs.push_back(llll(f[i], i));
  }

  for (auto q : x) {
    if (f.back() <= 0 && fs.back().first < q) {
      cout << -1 << ' ';
      continue;
    }
    ll res = 0;
    if (fs.back().first < q) {
      res = (q - fs.back().first + f.back() - 1) / f.back();
    }
    q -= res * f.back();
    cout << res * n + (*lower_bound(fs.begin(), fs.end(), llll(q, -1))).y
         << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("a.in", "r", stdin);
  init();
  int T;
  cin >> T;
  while (T--) solve();
}