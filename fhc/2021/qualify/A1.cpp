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

mii isVowel;

void init() {
  for (auto e : "AEIOU") isVowel[e] = true;
}

string s;

int solve(char c) {
  int step = 0;
  for (auto e : s) {
    if (e == c) continue;
    step += 1 + (isVowel[c] == isVowel[e]);
  }
  return step;
}

int _case = 0;

void solve() {
  _case++;
  cin >> s;
  int res = s.size() * 2;
  for (int e = 'A'; e <= 'Z'; e++) {
    res = min(res, solve(e));
  }
  cout << "Case #" << _case << ": " << res << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  freopen("consistency_chapter_1_input.txt", "r", stdin);
  freopen("consistency_chapter_1_output.txt", "w", stdout);
  int T;
  cin >> T;
  init();
  while (T--) solve();
}