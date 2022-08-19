// https://leetcode.com/problems/largest-sum-of-averages/

#include <vector>
using namespace std;

// time: O(n^2 * k)
// space: O(n)
class DP_1D {
public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    
    double prefixSum[101] {};
    for (int i = 0; i < n; i++)
      prefixSum[i+1] = prefixSum[i] + nums[i];
    
    double dp[100] {};
    for (int i = 0; i < n; i++)
      dp[i] = (prefixSum[n] - prefixSum[i]) / (n - i);
    
    for (int split = k - 1; split; split--) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          dp[i] = max(dp[i], dp[j] + (prefixSum[j] - prefixSum[i]) / (j - i));
        }
      }
    }
    
    return dp[0];
  }
};

// time: O(n^2 * k)
// space: O(n^2)
class TopDownMemo {
public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    
    double prefixSum[101] {};
    for (int i = 0; i < n; i++)
      prefixSum[i+1] = prefixSum[i] + nums[i];
    
    double memo[100][100] {};
    return solve(k - 1, prefixSum, 0, n, memo);
  }
  
private:
  double solve(int split, double* prefixSum, int start, int n, double (*memo)[100]) {
    if (split == 0)
      return (prefixSum[n] - prefixSum[start]) / (n - start);
    
    if (start == n or split >= n - start)
      return 0;
    
    if (memo[start][split])
      return memo[start][split];
    
    double result = 0;
    for (int i = start; i < n; i++) {
      double sumAvg = (prefixSum[i+1] - prefixSum[start]) / (i - start + 1) +
                       solve(split - 1, prefixSum, i + 1, n, memo);
      result = max(result, sumAvg);
    }
    
    return memo[start][split] = result;
  }
};