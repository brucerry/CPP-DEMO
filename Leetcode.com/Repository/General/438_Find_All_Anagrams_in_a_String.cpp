// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <vector>
#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    
    vector<int> charCountS (26, 0), charCountP (26, 0);
    for (int i = 0; i < p.length(); i++) {
      charCountP[p[i] - 'a']++;
      charCountS[s[i] - 'a']++;
    }

    vector<int> result;
    int l = 0, r = p.length();

    if (charCountP == charCountS) result.emplace_back(l);

    while (r < s.length()) {
      charCountS[s[r] - 'a']++;
      charCountS[s[l] - 'a']--;
      
      l++;
      r++;

      if (charCountP == charCountS) result.emplace_back(l);
    }

    return result;
  }
};