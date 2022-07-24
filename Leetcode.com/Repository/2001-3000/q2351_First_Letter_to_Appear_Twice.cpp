// https://leetcode.com/problems/first-letter-to-appear-twice/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  char repeatedCharacter(string& s) {
    int mask = 0;
    for (const char& c : s) {
      if (mask & (1 << (c - 'a')))
        return c;
      mask |= (1 << (c - 'a'));
    }
    return -1;
  }
};