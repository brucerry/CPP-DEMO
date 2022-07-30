// https://leetcode.com/problems/rearrange-array-elements-by-sign/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result (n);
    
    for (int i = 0, pos = 0, neg = 1; i < n; i++) {
      if (nums[i] > 0) {
        result[pos] = nums[i];
        pos += 2;
      }
      else {
        result[neg] = nums[i];
        neg += 2;
      }
    }
    
    return result;
  }
};