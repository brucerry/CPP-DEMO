// https://leetcode.com/problems/delete-operation-for-two-strings/

#include <vector>
#include <string>
using namespace std;

// time: O(r * c)
// space: O(c)
class Solution {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<int> dp (cols + 1);
    for (int c = cols - 1; c >= 0; c--)
      dp[c] = dp[c+1] + 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      int prev = dp.back();
      dp.back()++;
      
      for (int c = cols - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (word1[r] == word2[c])
          dp[c] = prev;
        else
          dp[c] = 1 + min(dp[c], dp[c+1]);
        
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};

// time: O(r * c)
// space: O(c)
class SubstractFromLCS {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<int> dp (cols + 1);
    for (int r = rows - 1; r >= 0; r--) {
      int prev = dp.back();
      
      for (int c = cols - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (word1[r] == word2[c])
          dp[c] = prev + 1;
        else
          dp[c] = max(dp[c], dp[c+1]);
        
        prev = tmp;
      }
    }
    
    return rows + cols - 2 * dp[0];
  }
};