// https://leetcode.com/problems/longest-string-chain/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// n = size of words
// s = len of each word
// time: O(n * log(n) + n * s^2)
// space: O(n)

class Solution {
public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
      return a.length() < b.length();
    });
    
    unordered_map<string, int> dp; // word, len
    int longest = 0;
    for (const string& word : words) {
      for (int i = 0; i < word.length(); i++) {
        string pre = word.substr(0, i) + word.substr(i + 1);
        dp[word] = max(dp[word], dp.count(pre) ? dp[pre] + 1 : 1);
      }
      longest = max(longest, dp[word]);
    }
    
    return longest;
  }
};