// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

#include <vector>
using namespace std;

// time: O(n^2 * d)
// space: O(min(n, d))

class Solution {
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size(), memo[301][11];
    for (int i = 0; i < 301; i++)
      for (int j = 0; j < 11; j++)
        memo[i][j] = INT_MAX;
    int result = solve(jobDifficulty, d, memo, 0, n);
    return result == INT_MAX ? -1 : result;
  }

private:
  int solve(vector<int>& jobDifficulty, int d, int (*memo)[11], int cur, int n) {
    if (n - cur < d)
      return INT_MAX;
    
    if (d == 0)
      return cur == n ? 0 : INT_MAX;

    if (memo[cur][d] != INT_MAX)
      return memo[cur][d];

    int& result = memo[cur][d], curMax = 0;
    for (int i = cur; i < n; i++) {
      curMax = max(curMax, jobDifficulty[i]);
      int jd = solve(jobDifficulty, d - 1, memo, i + 1, n);
      if (jd != INT_MAX) {
        result = min(result, jd + curMax);
      }
    }

    return result;
  }
};