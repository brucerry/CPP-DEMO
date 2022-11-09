// https://leetcode.com/problems/find-the-difference/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  char findTheDifference(string s, string t) {
    char result = 0;
    for (int i = 0; i < t.size(); i++)
      result ^= t[i] ^ s[i];
    return result;
  }
};