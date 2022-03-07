#include <bits/stdc++.h>
using namespace std;

vector<int> a;
void init() {
  int now = 0;
  while (a.size() < 1000) {
    now++;
    if (now % 3 == 0 || now % 10 == 3) continue;
    a.push_back(now);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << a[n - 1] << "\n";
  }
}