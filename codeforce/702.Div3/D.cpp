#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;
int f[200][200];
int d[200];
void rmq() {
  memset(f, 0, sizeof(f));
  for (int i = 0; i < a.size(); i++) f[i][i] = i;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if (a[f[i][j - 1]] > a[j])
        f[i][j] = f[i][j - 1];
      else
        f[i][j] = j;
    }
  }
}

void calc(int l, int r, int deep) {
  //   cout << l << " " << r << " " << deep << endl;
  if (l > r) return;
  int poss = f[l][r];
  //   cout << " pos = " << poss << endl;
  d[poss] = deep;
  calc(l, poss - 1, deep + 1);
  calc(poss + 1, r, deep + 1);
}

void solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  rmq();
  calc(0, a.size() - 1, 0);

  for (int i = 0; i < a.size(); i++) cout << d[i] << " ";
  cout << endl;
}

int main() {
  //   freopen("i.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) solve();
}