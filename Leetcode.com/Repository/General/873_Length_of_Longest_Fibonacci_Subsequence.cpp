// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    int dp[n][n];
    
    unordered_map<int, int> valIndex;
    int longest = 0;
    for (int j = 0; j < n; j++) {
      valIndex[arr[j]] = j;
      for (int i = 0; i < j; i++) {
        int idx = valIndex.count(arr[j] - arr[i]) ? valIndex[arr[j] - arr[i]] : -1;
        dp[i][j] = (arr[j] - arr[i] < arr[i] and idx >= 0) ? dp[idx][i] + 1 : 2;
        longest = max(longest, dp[i][j]);
      }
    }
    
    return longest >= 3 ? longest : 0;
  }
};