#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int nextGreaterElement(int n) {
    vector<int> a;

    while (n) {
      a.push_back(n % 10);
      n /= 10;
    }

    reverse(a.begin(), a.end());

    if (!next_permutation(a.begin(), a.end())) {
      return -1;
    }

    long long res = 0;

    for (auto e : a) {
      res = res * 10 + e;
    }

    if (res > INT_MAX) {
      return -1;
    }

    return res;
  }
};

int main() {
  Solution s;

  cout << s.nextGreaterElement(12) << endl;
}