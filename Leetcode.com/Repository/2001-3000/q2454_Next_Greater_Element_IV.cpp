// https://leetcode.com/problems/next-greater-element-iv/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result (n, -1), stk1, stk2, tmp;
    for (int i = 0; i < n; i++) {
      while (stk2.size() and nums[stk2.back()] < nums[i]) {
        result[stk2.back()] = nums[i];
        stk2.pop_back();
      }
      while (stk1.size() and nums[stk1.back()] < nums[i]) {
        tmp.emplace_back(stk1.back());
        stk1.pop_back();
      }
      while (tmp.size()) {
        stk2.emplace_back(tmp.back());
        tmp.pop_back();
      }
      stk1.emplace_back(i);
    }
    return result;
  }
};