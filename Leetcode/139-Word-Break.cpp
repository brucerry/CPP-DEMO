// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// s = length of string
// w = # of words
// Time: ~O(sw)
// Space: O(s)
class Solution {
public:

  // DP array
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp (s.length() + 1, false);
    dp.back() = true;

    for (int i = s.length() - 1; i >= 0; i--) {
      for (auto word : wordDict) {
        if (i + word.length() <= s.length() && s.substr(i, word.length()) == word) {
          dp[i] = dp[i + word.length()];
          if (dp[i]) break;
        }
      }
    }

    return dp.front();
  }





  // memorization
  // bool wordBreak(string s, vector<string>& wordDict, int idx, unordered_map<int, bool> &memo) {
  //   if (idx == s.length()) return true;
  //   if (memo.count(idx)) return memo[idx];

  //   for (auto word : wordDict) {
  //     int pos = s.find(word, idx);
  //     if (pos == idx) {
  //       if (wordBreak(s, wordDict, idx + word.length(), memo)) {
  //         memo[idx] = true;
  //         return true;
  //       }
  //     }
  //   }

  //   memo[idx] = false;
  //   return false;
  // }

  // bool wordBreak(string s, vector<string>& wordDict) {
  //   unordered_map<int, bool> memo;
  //   return wordBreak(s, wordDict, 0, memo);
  // }
};