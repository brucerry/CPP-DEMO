// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
using namespace std;

// time: O(s * w)
// space: O(s)

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<char> dp (s.length() + 1, 0);
    dp.back() = 1;
    
    for (int i = s.length() - 1; i >= 0; i--) {
      for (const string& word : wordDict) {
        if (s.find(word, i) == i) {
          dp[i] = dp[i + word.length()];
          if (dp[i])
            break;
        }
      }
    }
    
    return dp[0];
  }
};