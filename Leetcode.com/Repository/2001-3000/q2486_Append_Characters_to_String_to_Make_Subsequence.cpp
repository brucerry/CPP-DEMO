// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  int appendCharacters(string s, string t) {
    int j = 0;
    for (int i = 0; i < s.size() and j < t.size(); i++) {
      if (s[i] == t[j])
        j++;
    }
    return t.size() - j;
  }
};