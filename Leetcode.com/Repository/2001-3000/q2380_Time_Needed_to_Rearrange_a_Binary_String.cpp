// https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int secondsToRemoveOccurrences(string& s) {
    int seconds = 0, zeros = 0;
    for (const char& c : s) {
      if (c == '0') {
        zeros++;
        continue;
      }
      if (zeros)
        seconds = max(seconds + 1, zeros);
    }
    return seconds;
  }
};