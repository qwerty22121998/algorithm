#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

#ifdef SIEVE

const ll MAX_PRIME = 1e6 + 2;
int prime[MAX_PRIME] = {1};
void sieve() {
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i <= sqrt(MAX_PRIME); i++) {
    if (prime[i] == i) {
      ll j = i;
      while (j <= MAX_PRIME) {
        prime[j] = i;
        j += i;
      }
    }
  }
}
#endif

int n, m;

map<int, vector<ll>> x, y;

ll dsum(vector<ll> a) {
  sort(a.begin(), a.end());
  ll res = 0, sum = 0;
  for (int i = 0; i < a.size(); i++) {
    res += (a[i] * i - sum);
    sum += a[i];
  }
  return res;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int e;
      cin >> e;
      x[e].push_back(i);
      y[e].push_back(j);
    }
  }
  ll sum = 0;
  for (auto &p : x) {
    int c = p.first;
    sum += dsum(x[c]) + dsum(y[c]);
  }
  cout << sum << "\n";
}

int main() {
  // freopen(".inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
