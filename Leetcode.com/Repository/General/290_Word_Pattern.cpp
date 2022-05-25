// https://leetcode.com/problems/word-pattern/

#include <string>
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
    vector<string> words;
    stringstream ss (s);
    string word;
    while (getline(ss, word, ' '))
      words.emplace_back(word);
    
    if (pattern.length() != words.size())
      return false;
    
    unordered_map<char, string> charMap;
    unordered_set<string> bindedWord;
    for (int i = 0; i < pattern.length(); i++) {
      char& c = pattern[i];
      string& word = words[i];
      
      if (charMap.count(c) == 0) {
        if (bindedWord.count(word))
          return false;
        charMap[c] = word;
        bindedWord.emplace(word);
      }
      else if (charMap[c] != word)
        return false;
    }
    
    return true;
  }
};