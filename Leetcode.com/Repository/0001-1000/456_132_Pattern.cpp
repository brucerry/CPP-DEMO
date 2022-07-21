// https://leetcode.com/problems/132-pattern/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    stack<int> stack; // smaller indices with larger values
    int nums_k = INT_MIN; // larger index with mid value
    
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] < nums_k)
        return true;
      while (stack.size() and stack.top() < nums[i]) {
        nums_k = stack.top();
        stack.pop();
      }
      stack.emplace(nums[i]);
    }
    
    return false;
  }
};