// https://leetcode.com/problems/maximum-sum-circular-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class OnePass {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int sum = 0, curMax = 0, curMin = 0;
    int maxSum = nums[0], minSum = nums[0];
    for (const int& num : nums) {
      sum += num;
      curMax = max(curMax + num, num);
      maxSum = max(maxSum, curMax);
      curMin = min(curMin + num, num);
      minSum = min(minSum, curMin);
    }
    return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
  }
};

// time: O(n)
// space: O(1)
class KadaneAlgorithmTrick {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int maxSubarray = solve(nums, 1);
    int invertedMaxSubarray = solve(nums, -1);
    int circularMax = sum + invertedMaxSubarray;
    
    return circularMax == 0 ? maxSubarray : max(maxSubarray, circularMax);
  }
  
private:
  int solve(vector<int>& nums, int sign) {
    int result = nums[0] * sign, curSum = 0;
    for (const int& num : nums) {
      curSum = max(curSum + num * sign, num * sign);
      result = max(result, curSum);
    }
    return result;
  }
};