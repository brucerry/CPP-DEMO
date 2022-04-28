// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3)
      return false;
    
    int i = INT_MAX, j = INT_MAX;
    
    for (const int& num : nums) {
      if (num <= i)
        i = num;
      else if (num <= j)
        j = num;
      else
        return true;
    }
    
    return false;
  }
};