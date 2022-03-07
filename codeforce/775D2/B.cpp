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

#ifdef ERATOS

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
#endif

void init() {}

int n;
vector<ll> a;

void solve() {
  cin >> n;
  a.resize(n);
  for (auto &e : a) cin >> e;
  sort(a.begin(), a.end());
  if (a.back() == 0) {
    cout << "0\n";
    return;
  }
  ll sum = 0;
  for (int i = 0; i < a.size() - 1; i++) sum += a[i];
  cout << max(ll(1), a.back() - sum) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("a.in", "r", stdin);
  init();
  int T;
  cin >> T;
  while (T--) solve();
}