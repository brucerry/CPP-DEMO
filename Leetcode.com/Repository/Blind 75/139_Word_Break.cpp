// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
using namespace std;

// s = len of s
// n = size of wordDict
// time: O(s * n)
// space: O(s)

class Solution {
public:
  bool wordBreak(string& s, vector<string>& wordDict) {
    int n = s.length();
    vector<char> dp (n + 1);
    dp.back() = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      for (const string& word : wordDict) {
        if (i == s.find(word, i))
          dp[i] |= dp[i + word.length()];
        if (dp[i])
          break;
      }
    }
    
    return dp[0];
  }
};