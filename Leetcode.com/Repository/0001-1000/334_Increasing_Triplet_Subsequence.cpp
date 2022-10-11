// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    for (const int& num : nums) {
      if (num <= min1)
        min1 = num;
      else if (num <= min2)
        min2 = num;
      else
        return true;
    }
    return false;
  }
};