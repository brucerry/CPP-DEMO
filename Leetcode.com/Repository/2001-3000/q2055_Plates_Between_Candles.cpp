// https://leetcode.com/problems/plates-between-candles/

#include <vector>
#include <string>
using namespace std;

// n = len of s
// q = size of queries
// time: O(n + q)
// space: O(n)

class Solution {
public:
  vector<int> platesBetweenCandles(string& s, vector<vector<int>>& queries) {
    int n = s.length();
    
    // 2D array "counts"
    // if s[i] is '|', then counts[i] is { value } = accumulation of valid '*' from left
    // if s[i] is '*', then counts[i] is { left, right } = { accumulation result of left '|', accumulation result of right '|'}
    vector<vector<int>> counts (n);
    int plateCount = -1;
    for (int i = 0, left = 0; i < n; i++) {
      char c = s[i];
      if (c == '*') {
        counts[i].emplace_back(left);
        if (plateCount >= 0)
          plateCount++;
      }
      else {
        if (plateCount == -1)
          plateCount++;
        left = plateCount;
        counts[i].emplace_back(plateCount);
      }
    }
    for (int i = n - 1, right = counts.back()[0]; i >= 0; i--) {
      char c = s[i];
      if (c == '*')
        counts[i].emplace_back(right);
      else
        right = counts[i][0];
    }
    
    int q = queries.size();
    vector<int> result (q);
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      int leftval = s[l] == '*' ? counts[l][1] : counts[l][0];
      int rightval = s[r] == '*' ? counts[r][0] : counts[r][0]; // same for both conditions, can be simply modified, I keep this for lucid
      result[i] = max(0, rightval - leftval);
    }
    
    return result;
  }
};