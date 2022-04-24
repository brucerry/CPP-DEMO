// https://leetcode.com/problems/word-break-ii/

#include <vector>
#include <string>
using namespace std;

// s = len of s
// n = len of wordDict
// time: O(n^s)
// space: O(s)

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans;
    vector<string> words;
    solve(s, wordDict, ans, words, 0);
    return ans;
  }
  
private:
  void solve(string& s, vector<string>& wordDict, vector<string>& ans, vector<string>& words, int i) {
    if (i == s.length()) {
      addWordsToAns(ans, words);
      return;
    }
    
    for (const string& word : wordDict) {
      if (i == s.find(word, i)) {
        words.emplace_back(word);
        solve(s, wordDict, ans, words, i + word.length());
        words.pop_back();
      }
    }
  }
  
  void addWordsToAns(vector<string>& ans, vector<string>& words) {
    string sentence;
    
    for (int i = 0; i < words.size(); i++) {
      if (i > 0)
        sentence += ' ';
      sentence += words[i];
    }
    
    ans.emplace_back(sentence);
  }
};