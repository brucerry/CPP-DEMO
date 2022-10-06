// https://leetcode.com/problems/percentage-of-letter-in-string/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int percentageLetter(string& s, char letter) {
    return count(s.begin(), s.end(), letter) * 100 / s.size();
  }
};