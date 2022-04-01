// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
using namespace std;

// time: O(s * w)
// space: O(s)

class Solution {  
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> dp (s.length() + 1, false);
    dp.back() = true;
    
    for (int i = s.length() - 1; i >= 0; i--) {
      for (string& word : wordDict) {
        if (i == s.find(word, i)) {
          dp[i] = dp[i + word.length()];
          if (dp[i]) break;
        }
      }
    }
    
    return dp[0];
  }
};

// memorization
// class Solution {
// private:
//   bool wordBreak(string& s, vector<string>& wordDict, int i, vector<int>& memo) {
//     if (i == s.length()) return true;
//     if (memo[i] != -1) return memo[i];
    
//     for (string& word : wordDict) {
//       if (i == s.find(word, i) && wordBreak(s, wordDict, i + word.length(), memo)) {
//         return memo[i] = true;
//       }
//     }
    
//     return memo[i] = false;
//   }
  
// public:
//   bool wordBreak(string s, vector<string>& wordDict) {
//     vector<int> memo (s.length(), -1);
//     return wordBreak(s, wordDict, 0, memo);
//   }
// };