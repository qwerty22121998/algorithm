#include <bits/stdc++.h>

using namespace std;

int minRemovals(vector<int> arr, int k) {
  sort(arr.begin(), arr.end());
  int res = arr.size();
  for (auto it = arr.begin(); it != arr.end(); it++) {
    auto l = lower_bound(arr.begin(), it, *it - k);

    int size = it - l + 1;

    res = min(res, int(arr.size() - size));
  }

  return res;
}

int main() {
  vector<int> a{0, 0, 0, 0, 0};
  int k = -1;
  cout << minRemovals(a, k) << endl;
}