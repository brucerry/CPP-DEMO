// https://leetcode.com/problems/132-pattern/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int midVal = INT_MIN; // mid value but larger index
    stack<int> stack; // larger values but smaller indices
    
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < midVal)
        return true;
      while (stack.size() and nums[i] > stack.top()) {
        midVal = stack.top();
        stack.pop();
      }
      stack.emplace(nums[i]);
    }
    
    return false;
  }
};