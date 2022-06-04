// https://leetcode.com/problems/steps-to-make-array-non-decreasing/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int totalSteps(vector<int>& nums) {
    stack<pair<int, int>> stack; // num, step
    stack.emplace(nums[0], 0);
    
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
      int step = 0;
      while (stack.size() and stack.top().first <= nums[i]) {
        step = max(step, stack.top().second);
        stack.pop();
      }
      step = stack.size() ? step + 1 : 0;
      stack.emplace(nums[i], step);
      result = max(result, step);
    }
    
    return result;
  }
};