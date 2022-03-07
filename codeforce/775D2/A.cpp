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

#ifdef ERATOS
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
#endif

void init() {}

int n;
vector<int> a;
void solve() {
  cin >> n;
  a.resize(n);
  for (auto &e : a) cin >> e;
  int from = 0;
  int to = n - 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      from = i;
    } else {
      break;
    }
  }
  for (int j = n - 1; j; j--) {
    if (a[j] == 1) {
      to = j;
    } else {
      break;
    }
  }
  cout << max(0, to - from) << '\n';
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