// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int one = INT_MAX, two = INT_MAX;
    for (const int& num : nums) {
      if (one >= num)
        one = num;
      else if (two >= num)
        two = num;
      else
        return true;
    }
    return false;
  }
};