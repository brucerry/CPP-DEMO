// https://leetcode.com/problems/first-missing-positive/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    
    for (int& num : nums) {
      if (num < 0)
        num = 0;
    }
    
    for (const int& num : nums) {
      int i = abs(num) - 1;
      
      if (0 <= i and i < n) {
        if (nums[i] > 0)
          nums[i] = -nums[i];
        else if (nums[i] == 0)
          nums[i] = -(n + 1);
      }
    }
    
    for (int i = 0; i < n; i++) {
      if (nums[i] >= 0)
        return i + 1;
    }
    
    return n + 1;
  }
};