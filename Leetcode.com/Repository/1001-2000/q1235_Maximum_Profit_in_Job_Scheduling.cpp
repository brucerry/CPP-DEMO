// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    
    vector<vector<int>> jobs;
    for (int i = 0; i < n; i++) {
      jobs.push_back({ startTime[i], endTime[i], profit[i] });
    }
    sort(jobs.begin(), jobs.end());

    int dp[50001] {};
    for (int i = n - 1; i >= 0; i--) {
      int e = jobs[i][1], p = jobs[i][2];
      int j = lower_bound(jobs.begin(), jobs.end(), vector<int>{e}) - jobs.begin();
      dp[i] = max(dp[i+1], dp[j] + p);
    }

    return dp[0];
  }
};