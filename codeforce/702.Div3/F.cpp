#include <bits/stdc++.h>

using namespace std;

#define x first

#define y second

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

int n;
vi a;

void solve() {
  cin >> n;
  a.resize(n);
  for (auto &e : a) cin >> e;
  mii cnt;
  for (auto e : a) cnt[e]++;
  vi c;
  for (auto e : cnt) {
    c.push_back(e.second);
  }
  sort(c.begin(), c.end());
  for (int i = 1; i < c.size(); i++) {
    c[i] += c[i - 1];
  }
  int res = c.back();

  for (int i = 0; i < c.size(); i++) {
    int now = c[i];
    if (i > 0) now -= c[i - 1];
    int pre = 0, post = 0;
    if (i != 0) {
      pre = c[i - 1];
    }
    if (i != c.size() - 1) {
      post = c.back() - c[i] - now * (c.size() - i - 1);
    }
    int total = pre + post;
    res = min(res, total);
  }
  cout << res << '\n';
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