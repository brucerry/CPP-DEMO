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
    unordered_map<string, vector<string>> groups;
    for (const string& word : strs) {
      string s = "00000000000000000000000000";
      for (const char& c : word) {
        s[c - 'a']++;
      }
      groups[s].emplace_back(word);
    }
    
    vector<vector<string>> result;
    
    for (const auto& [ _, group ] : groups) {
      result.emplace_back(group);
    }
    
    return result;
  }
};