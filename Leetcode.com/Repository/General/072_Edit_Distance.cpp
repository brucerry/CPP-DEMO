// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

// m = len of word1
// n = len of word2
// time: O(m * n)
// space: O(n)
class Solution {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<int> dp (cols + 1);
    for (int c = 0; c < cols; c++)
      dp[c] = dp[c+1] + 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      int prev = dp.back();
      dp.back()++;
      
      for (int c = cols - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (word1[r] == word2[c])
          dp[c] = prev;
        else
          dp[c] = 1 + min({ dp[c], dp[c+1], prev });
        
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};

// m = len of word1
// n = len of word2
// time: O(m * n)
// space: O(m * n)
class DP_2D {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
    for (int c = cols - 1; c >= 0; c--)
      dp[rows][c] = dp[rows][c+1] + 1;
    for (int r = rows - 1; r >= 0; r--)
      dp[r][cols] = dp[r+1][cols] + 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (word1[r] == word2[c])
          dp[r][c] = dp[r+1][c+1];
        else
          dp[r][c] = 1 + min({ dp[r+1][c+1], dp[r+1][c], dp[r][c+1] });
      }
    }
    
    return dp[0][0];
  }
};