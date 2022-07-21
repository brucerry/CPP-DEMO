// https://leetcode.com/problems/split-array-largest-sum/

#include <vector>
using namespace std;

// n = size of nums
// s = sum of nums
// time: O(n * log(s))
// space: O(1)
class BinarySearch {
public:
  int splitArray(vector<int>& nums, int m) {
    int l = 0, r = 0;
    for (const int& num : nums) {
      l = max(l, num);
      r += num;
    }
    
    while (l < r) {
      int mid = l + ((r - l) >> 1);
      if (canSplit(nums, m, mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
  
private:
  bool canSplit(vector<int>& nums, int group, int splitMax) {
    int subarray = 0, curSum = 0;
    for (const int& num : nums) {
      curSum += num;
      if (curSum > splitMax) {
        curSum = num;
        subarray++;
      }
    }
    return subarray + 1 <= group;
  }
};

// time: O(n^2 * m)
// space: O(n * m)
class TopDownMemo {
public:
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    
    vector<int> prefixSum (n + 1);
    for (int i = 1; i <= n; i++) {
      prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }
    
    vector<vector<int>> memo (n, vector<int>(m + 1, INT_MAX));
    return solve(nums, m, 0, prefixSum, memo);
  }
  
private:
  int solve(vector<int>& nums, int m, int start, vector<int>& prefixSum, vector<vector<int>>& memo) {
    int n = nums.size();
    
    if (m == 1)
      return prefixSum[n] - prefixSum[start];
    
    if (memo[start][m] != INT_MAX)
      return memo[start][m];
    
    for (int i = start; i < n - m + 1; i++) {
      int splitMax = prefixSum[i+1] - prefixSum[start];
      splitMax = max(splitMax, solve(nums, m - 1, i + 1, prefixSum, memo));
      memo[start][m] = min(memo[start][m], splitMax);
      if (splitMax >= memo[start][m])
        break;
    }
    
    return memo[start][m];
  }
};