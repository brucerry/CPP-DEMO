// https://leetcode.com/problems/single-number-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (const int& num : nums) {
      ones = (ones ^ num) & ~twos;
      twos = (twos ^ num) & ~ones;
    }
    return ones;
  }
};