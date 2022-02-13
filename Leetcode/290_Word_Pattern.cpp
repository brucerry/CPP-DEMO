// https://leetcode.com/problems/word-pattern/

#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> map;
    unordered_set<string> set;
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
      words.push_back(word);
    }

    if (words.size() != pattern.size()) return false;

    for (int i = 0; i < pattern.length(); i++) {
      if (map.count(pattern[i]) == 0) {
        if (set.count(words[i])) return false;
        map[pattern[i]] = words[i];
        set.insert(words[i]);
      }
      else if (map[pattern[i]] != words[i]) return false;
    }
    return true;
  }
};