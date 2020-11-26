#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    vector<int> f;
    for (auto e : height) {
      if (f.empty()) {
        f.push_back(e);
      } else {
        f.push_back(max(f.back(), e));
      }
    }
    vector<int> g;
    for (int i = height.size() - 1; i >= 0; i--) {
      if (g.empty())
        g.push_back(height[i]);
      else
        g.push_back(max(height[i], g.back()));
    }
    reverse(g.begin(), g.end());
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
      int water = max(0, min(f[i], g[i]) - height[i]);
      res += water;
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << solution.trap(input) << endl;
}
