// https://leetcode.com/problems/maximum-erasure-value/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> numSet;
    
    int curSum = 0, score = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      curSum += nums[r];
      while (numSet.count(nums[r])) {
        numSet.erase(nums[l]);
        curSum -= nums[l++];
      }
      numSet.insert(nums[r]);
      score = max(score, curSum);
    }
    
    return score;
  }
};