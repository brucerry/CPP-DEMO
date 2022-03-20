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

    for (auto& pair : charCountS) {
      if (charCountS[pair.first] != charCountT[pair.first]) return false;
    }

    return true;
  }
};