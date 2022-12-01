// https://leetcode.com/problems/determine-if-string-halves-are-alike/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool halvesAreAlike(string s) {
    int mask = 0;
    mask |= 1 << ('a' - 'a');
    mask |= 1 << ('e' - 'a');
    mask |= 1 << ('i' - 'a');
    mask |= 1 << ('o' - 'a');
    mask |= 1 << ('u' - 'a');
    
    int n = s.size(), a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      bool isVowel = (mask & (1 << (tolower(s[i]) - 'a'))) > 0;
      if (i < n / 2)
        a += isVowel;
      else
        b += isVowel;
    }

    return a == b;
  }
};