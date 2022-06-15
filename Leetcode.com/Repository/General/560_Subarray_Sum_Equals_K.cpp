// https://leetcode.com/problems/subarray-sum-equals-k/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount { // prefixSum, count
      { 0, 1 }
    };
    
    int subarray = 0, curSum = 0;
    for (const int& num : nums) {
      curSum += num;
      if (prefixCount.count(curSum - k))
        subarray += prefixCount[curSum - k];
      prefixCount[curSum]++;
    }
    
    return subarray;
  }
};