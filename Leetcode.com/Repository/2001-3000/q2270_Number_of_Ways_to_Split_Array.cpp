// https://leetcode.com/problems/number-of-ways-to-split-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  int waysToSplitArray(vector<int>& nums) {    
    long sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int way = 0;
    long curSum = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      curSum += nums[i];
      if (curSum >= sum - curSum)
        way++;
    }
    
    return way;
  }
};

// time: O(n)
// space: O(n)
class PrefixSumArray {
public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    
    vector<long> prefixSum (nums.begin(), nums.end());
    for (int i = 1; i < n; i++) {
      prefixSum[i] += prefixSum[i-1];
    }
    
    int way = 0, endIndex = n - 1;
    for (int i = 0; i < endIndex; i++) {
      if (prefixSum[i] >= prefixSum[endIndex] - prefixSum[i])
        way++;
    }
    
    return way;
  }
};