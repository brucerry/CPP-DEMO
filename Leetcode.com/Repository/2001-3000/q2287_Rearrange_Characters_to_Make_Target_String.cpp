// https://leetcode.com/problems/rearrange-characters-to-make-target-string/

#include <string>
using namespace std;

// s = len of s
// t = len of target
// time: O(s + t)
// space: O(1)

class Solution {
public:
  int rearrangeCharacters(string& s, string& target) {
    int sCount[26] {}, tCount[26] {};
    for (const char& c : s) {
      sCount[c - 'a']++;
    }
    for (const char& c : target) {
      tCount[c - 'a']++;
    }

    int result = INT_MAX;
    for (int i = 0; i < 26; i++) {
      if (tCount[i]) {
        result = min(result, sCount[i] / tCount[i]);
      }
    }

    return result;
  }
};