// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result (nums.size());
    
    int prefix = 1;
    int postfix = 1;

    for (int i = 0; i < nums.size(); i++) {
      result[i] = prefix;
      prefix *= nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--) {
      result[i] *= postfix;
      postfix *= nums[i];
    }

    return result;
  }
};