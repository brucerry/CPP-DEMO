// https://leetcode.com/problems/single-number/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (const int& num : nums) {
      ans ^= num;
    }

    return ans;
  }
};