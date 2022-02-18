// https://leetcode.com/problems/word-break-ii/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
  vector<vector<string>> wordBreak(string s, vector<string>& wordDict, int idx, unordered_map<int, vector<vector<string>>>& memo) {
    if (idx == s.length()) return {{}};
    if (memo.count(idx)) return memo[idx];

    vector<vector<string>> result;

    for (auto word : wordDict) {
      int pos = s.find(word, idx);
      if (pos == idx) {
        for (auto subSentence : wordBreak(s, wordDict, idx + word.length(), memo)) {
          subSentence.insert(subSentence.begin(), word);
          result.push_back(subSentence);
        }
      }
    }

    memo[idx] = result;
    return result;
  }

  vector<string> concatSentences(vector<vector<string>> sentences) {
    vector<string> result;
    for (auto sentence : sentences) {
      string str = sentence[0];
      for (int i = 1; i < sentence.size(); i++) {
        str += " " + sentence[i];
      }
      result.push_back(str);
    }
    return result;
  }

public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<int, vector<vector<string>>> memo;
    vector<vector<string>> sentences = wordBreak(s, wordDict, 0, memo);
    return concatSentences(sentences);
  }
};