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
    int maxSubarray = solve(nums, 1);
    int minSubarray = solve(nums, -1);

    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int circularMax = sum + minSubarray;
    if (circularMax == 0)
      return maxSubarray;

    return max(maxSubarray, circularMax);
  }
  
private:
  int solve(vector<int>& nums, char sign) {
    int result = sign * nums[0];
    int curSum = 0;
    for (const int& num : nums) {
      curSum = max(curSum + sign * num, sign * num);
      result = max(result, curSum);
    }
    return result;
  }
};