// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
using namespace std;

// s = len of s
// w = size of wordDict
// time: O(s * w)
// space: O(s)

class Solution {
public:
  bool wordBreak(string& s, vector<string>& wordDict) {
    vector<char> dp (s.length() + 1);
    dp.back() = 1;
    
    for (int i = s.length() - 1; i >= 0; i--) {
      for (const string& word : wordDict) {
        if (i == s.find(word, i) and dp[i + word.length()]) {
          dp[i] = 1;
          break;
        }
      }
    }
    
    return dp[0];
  }
};