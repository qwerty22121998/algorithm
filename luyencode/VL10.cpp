#include <bits/stdc++.h>
using namespace std;

string n;

int main() {
  cin >> n;
  int res = n.size();
  if (n[0] == '-') res--;
  cout << res;
}