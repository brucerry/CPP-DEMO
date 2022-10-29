// https://leetcode.com/problems/odd-string-difference/

#include <string>
#include <vector>
#include <map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string oddString(vector<string>& words) {
    map<vector<int>, vector<string>> map; // diffs, strings
    vector<int> diffs;
    for (const string& word : words) {
      diffs = {};
      for (int i = 1; i < word.size(); i++) {
        diffs.emplace_back(word[i] - word[i-1]);
      }
      map[diffs].emplace_back(word);
    }
    
    for (const auto& [ _, strings ] : map) {
      if (strings.size() == 1)
        return strings[0];
    }
    
    return "";
  }
};