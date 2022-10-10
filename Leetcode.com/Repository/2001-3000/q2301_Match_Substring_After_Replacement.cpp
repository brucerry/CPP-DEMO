// https://leetcode.com/problems/match-substring-after-replacement/

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// n = len of s
// m = len of sub
// k = size of mappings
// time: O(k + n * m)
// space: O(k)

class Solution {
public:
  bool matchReplacement(string& s, string& sub, vector<vector<char>>& mappings) {
    unordered_map<char, unordered_set<char>> map;
    for (const auto& mapping : mappings) {
      map[mapping[0]].emplace(mapping[1]);
    }

    int s_len = s.size(), sub_len = sub.size();
    for (int i = 0, j = 0; i < s_len - sub_len + 1; i++) {
      for (j = 0; j < sub_len; j++) {
        if (s[i+j] == sub[j])
          continue;
        if (map.count(sub[j]) == 0 or map[sub[j]].count(s[i+j]) == 0)
          break;
      }
      if (j == sub_len)
        return true;
    }

    return false;
  }
};