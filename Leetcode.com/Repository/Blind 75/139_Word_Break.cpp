// https://leetcode.com/problems/word-break/

#include <vector>
#include <string>
using namespace std;

// n = len of s
// w = size of wordDict
// time: O(n^2 * w)
// space: O(n)

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