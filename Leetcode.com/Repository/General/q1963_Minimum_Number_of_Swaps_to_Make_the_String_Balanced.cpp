// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minSwaps(string& s) {
    int close = 0, maxClose = 0;
    
    for (const char& c : s) {
      if (c == '[')
        close--;
      else {
        close++;
        maxClose = max(maxClose, close);
      }
    }
    
    return (maxClose + 1) >> 1;
  }
};