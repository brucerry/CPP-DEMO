// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s) where s == t
// space: O(s + t)

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, int> charCountS, charCountT;

    for (int i = 0; i < s.length(); i++) {
      charCountS[s[i]]++;
      charCountT[t[i]]++;
    }

    for (const auto& [ ch, count ] : charCountS) {
      if (count != charCountT[ch]) return false;
    }

    return true;
  }
};