// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)

class Solution {
public:
  int minDistance(string& word1, string& word2) {
    int rows = word1.length();
    int cols = word2.length();
    
    vector<int> dp (cols + 1);
    
    for (int c = 0; c <= cols; c++)
      dp[c] = word2.length() - c;
    
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