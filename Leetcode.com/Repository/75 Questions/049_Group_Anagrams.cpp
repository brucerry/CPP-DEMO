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

    for (string& s : strs) {
      string s = "00000000000000000000000000";
      for (char& c : s) {
        s[c - 'a']++;
      }
      map[s].emplace_back(s);
    }

    vector<vector<string>> result;

    for (auto& pair : map) {
      result.emplace_back(pair.second);
    }

    return result;
  }
};