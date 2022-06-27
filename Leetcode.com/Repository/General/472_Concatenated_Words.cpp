// https://leetcode.com/problems/concatenated-words/

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

// n = size of words
// w = len of each word
// time: O(n * w^3)
// space: O(n)

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
      return a.length() < b.length();
    });
    
    unordered_set<string> preWords;
    vector<string> result;
    for (const string& word : words) {
      if (wordBreak(word, preWords)) {
        result.push_back(word);
      }
      preWords.insert(word);
    }
    
    return result;
  }
  
private:
  bool wordBreak(const string& word, unordered_set<string>& preWords) {
    int n = word.length();
    vector<char> dp (n + 1);
    dp.back() = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        string pre = word.substr(i, j - i + 1);
        if (preWords.count(pre))
          dp[i] |= dp[i + pre.length()];
        if (dp[i])
          break;
      }
    }
    
    return dp[0];
  }
};