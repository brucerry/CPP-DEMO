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
    unordered_map<string, vector<string>> map;
    
    for (const string& str : strs) {
      string s = "00000000000000000000000000";
      for (const char& ch : str) {
        s[ch - 'a']++;
      }
      map[s].emplace_back(str);
    }
    
    vector<vector<string>> ans;
    
    for (const auto& [ _, group ] : map) {
      ans.emplace_back(group);
    }
    
    return ans;
  }
};