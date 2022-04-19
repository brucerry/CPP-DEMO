// https://leetcode.com/problems/edit-distance/

#include <string>
#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)

class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<int> dp (word2.length() + 1);
    
    for (int i = 0; i < dp.size(); i++) {
      dp[i] = word2.length() - i;
    }
    
    for (int r = word1.length() - 1; r >= 0; r--) {
      int prev = dp.back();
      dp.back() = word1.length() - r;
      for (int c = word2.length() - 1; c >= 0; c--) {
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