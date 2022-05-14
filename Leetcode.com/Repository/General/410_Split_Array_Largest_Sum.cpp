// https://leetcode.com/problems/split-array-largest-sum/

#include <vector>
using namespace std;

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
    
    int result = r;
    
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      
      if (canSplit(nums, m, mid)) {
        result = mid;
        r = mid - 1;
      }
      else
        l = mid + 1;
    }
    
    return result;
  }
  
private:
  bool canSplit(vector<int>& nums, int m, int largest) {
    int subarray = 0, curSum = 0;
    for (const int& num : nums) {
      curSum += num;
      if (curSum > largest) {
        subarray++;
        curSum = num;
      }
    }
    return subarray + 1 <= m;
  }
};

// time: O(n^2 * m)
// space: O(n * m)
class TopDownMemo {
public:
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<vector<int>> memo (n, vector<int>(m + 1, INT_MAX));
    return solve(nums, m, 0, memo);
  }
  
private:
  int solve(vector<int>& nums, int m, int start, vector<vector<int>>& memo) {
    if (m == 1) {
      int sum = 0;
      for (int i = start; i < nums.size(); i++)
        sum += nums[i];
      return sum;
    }
    
    if (memo[start][m] != INT_MAX)
      return memo[start][m];
    
    int curSum = 0;
    for (int i = start; i < nums.size() - m + 1; i++) {
      curSum += nums[i];
      int maxSum = max(curSum, solve(nums, m - 1, i + 1, memo));
      memo[start][m] = min(memo[start][m], maxSum);
      if (curSum > memo[start][m])
        break;
    }
    
    return memo[start][m];
  }
};