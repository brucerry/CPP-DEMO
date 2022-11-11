// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    char n = s1.size(), cnt1[26] {}, cnt2[26] {};
    for (int i = 0; i < n; i++) {
      cnt1[s1[i] - 'a']++;
      cnt2[s2[i] - 'a']++;
    }
    
    char swaps = 0;
    for (int i = 0; i < n; i++) {
      char c1 = s1[i] - 'a', c2 = s2[i] - 'a';
      if (cnt1[c1] != cnt2[c1] or cnt1[c2] != cnt2[c2])
        return false;
      swaps += c1 != c2;
    }
    return (swaps + 1) / 2 <= 1;
  }
};