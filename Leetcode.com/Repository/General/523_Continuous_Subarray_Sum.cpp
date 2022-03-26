// https://leetcode.com/problems/continuous-subarray-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainder { {0, -1} }; // remainder, end index
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      int remain = sum % k;

      if (remainder.count(remain) == 0) {
        remainder[remain] = i;
      }
      else if (i - remainder[remain] >= 2) {
        return true;
      }
    }

    return false;
  }
};