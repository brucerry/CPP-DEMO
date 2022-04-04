// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s + t) -> O(s)
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

    for (const auto& [ ch, _ ] : charCountS) {
      if (charCountS[ch] != charCountT[ch]) return false;
    }

    return true;
  }
};