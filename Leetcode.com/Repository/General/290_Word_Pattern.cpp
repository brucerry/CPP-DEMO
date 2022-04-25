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
  bool wordPattern(string pattern, string s) {
    vector<string> words;
    stringstream ss (s);
    string word;
    while (getline(ss, word, ' ')) {
      words.emplace_back(word);
    }
    
    if (words.size() != pattern.length())
      return false;
    
    unordered_map<char, string> map;
    unordered_set<string> set;
    
    for (int i = 0; i < words.size(); i++) {
      if (map.count(pattern[i]) == 0) {
        if (set.count(words[i]))
          return false;
        set.emplace(words[i]);
        map[pattern[i]] = words[i];
      }
      else if (map[pattern[i]] != words[i])
        return false;
    }
    
    return true;
  }
};