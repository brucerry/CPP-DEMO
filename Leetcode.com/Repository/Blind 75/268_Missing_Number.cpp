// https://leetcode.com/problems/missing-number/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:

  // XOR solution
  int missingNumber(vector<int>& nums) {
    int ans = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      ans ^= i ^ nums[i];
    }

    return ans;
  }

  // SUM solution
  // int missingNumber(vector<int>& nums) {
  //   int ans = nums.size();

  //   for (int i = 0; i < nums.size(); i++) {
  //     ans += i - nums[i];
  //   }

  //   return ans;
  // }
};