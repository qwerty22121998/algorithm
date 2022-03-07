#include <bits/stdc++.h>

using namespace std;

const int N = 4e5;
int cal[N], a, b;

void solve() {
  cin >> a >> b;
  int d = abs(a - b);
  int now = 0;
  if (d % 2 == 0) {
    cal[++now] = d / 2;
    for (int i = 1; i <= min(a, b); i++) {
      now++;
      cal[now] = cal[now - 1] + 2;
    }
  } else {
    cal[++now] = d / 2;
    cal[++now] = d / 2 + 1;
    for (int i = 1; i <= min(a, b) * 2; i++) {
      now++;
      cal[now] = cal[now - 1] + 1;
    }
  }
  cout << now << "\n";
  for (int i = 1; i <= now; i++) cout << cal[i] << " ";
  cout << "\n";
}

int main() {
  freopen("a.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}