// https://leetcode.com/problems/word-pattern/

#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool wordPattern(string& pattern, string& s) {
    stringstream ss (s);
    string word;
    vector<string> words;
    while (getline(ss, word, ' ')) {
      words.push_back(word);
    }
    
    if (words.size() != pattern.length())
      return false;
    
    unordered_map<char, string> patternToWord;
    unordered_set<string> usedWord;
    for (int i = 0; i < words.size(); i++) {
      char p = pattern[i];
      string& word = words[i];
      
      if (patternToWord.count(p) == 0) {
        if (usedWord.count(word))
          return false;
        patternToWord[p] = word;
        usedWord.insert(word);
      }
      else if (patternToWord[p] != word)
        return false;
    }
    
    return true;
  }
};