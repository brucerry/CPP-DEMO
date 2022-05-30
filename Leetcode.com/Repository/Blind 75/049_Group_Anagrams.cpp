// https://leetcode.com/problems/group-anagrams/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// s = # of strs
// c = # of chars in each of strs
// time: O(s * c)
// space: O(s)

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> patternGroup;
    for (const string& str : strs) {
      string pattern = "00000000000000000000000000";
      for (const char& c : str) {
        pattern[c - 'a']++;
      }
      patternGroup[pattern].emplace_back(str);
    }
    
    vector<vector<string>> result;
    for (const auto& [ _, group ] : patternGroup) {
      result.emplace_back(group);
    }
    
    return result;
  }
};