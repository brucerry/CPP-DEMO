// https://leetcode.com/problems/continuous-subarray-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> umap { // remainder, index
      { 0, -1 }
    };
    for (int i = 0, curSum = 0; i < nums.size(); i++) {
      curSum += nums[i];
      int remain = curSum % k;
      if (umap.count(remain) == 0)
        umap[remain] = i;
      else if (i - umap[remain] >= 2)
        return true;
    }
    return false;
  }
};