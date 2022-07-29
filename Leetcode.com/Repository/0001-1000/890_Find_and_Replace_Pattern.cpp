// https://leetcode.com/problems/find-and-replace-pattern/

#include <vector>
#include <string>
#include <array>
using namespace std;

// w = size of words
// p = len of pattern
// time: O(w * p)
// space: O(1)

class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
    vector<string> result;
    for (const string& word : words) {
      if (isMatch(word, pattern))
        result.emplace_back(word);
    }
    return result;
  }
  
private:
  bool isMatch(const string& word, string& pattern) {
    array<char, 26> wordMap {}, patternMap {};
    for (int i = 0; i < word.length(); i++) {
      char w = word[i], p = pattern[i];
      if ((wordMap[w - 'a'] and wordMap[w - 'a'] != p) or
          (patternMap[p - 'a'] and patternMap[p - 'a'] != w))
        return false;
      wordMap[w - 'a'] = p;
      patternMap[p - 'a'] = w;
    }
    return true;
  }
};