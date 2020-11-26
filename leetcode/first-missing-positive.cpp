#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int has1 = 0;
    for (auto& e : nums) {
      if (e == 1) has1 = 1;
      if (e<1 | e> n) e = 1;
    }
    if (!has1) return 1;
    for (int i = 0; i < nums.size(); i++) {
      nums[(nums[i] - 1) % n] += n;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= n) return i + 1;
    }
    return n + 1;
  }
};

int main() {
  auto solution = new Solution();
  vector<int> input{7, 8, 9, 11, 12};
  cout << solution->firstMissingPositive(input) << endl;
}