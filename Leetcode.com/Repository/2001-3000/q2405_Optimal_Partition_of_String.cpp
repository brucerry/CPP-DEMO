// https://leetcode.com/problems/optimal-partition-of-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int partitionString(string& s) {
    int usedMask = 0, result = 1;
    for (const char& c : s) {
      if (usedMask & (1 << c - 'a')) {
        usedMask = 0;
        result++;
      }
      usedMask |= 1 << c - 'a';
    }
    return result;
  }
};