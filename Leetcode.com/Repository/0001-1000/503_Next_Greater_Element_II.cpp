// https://leetcode.com/problems/next-greater-element-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> stack, result (n, -1);
    
    for (int i = 0; i < n * 2; i++) {
      while (stack.size() and nums[stack.back()] < nums[i % n]) {
        result[stack.back()] = nums[i % n];
        stack.pop_back();
      }
      stack.emplace_back(i % n);
    }
    
    return result;
  }
};