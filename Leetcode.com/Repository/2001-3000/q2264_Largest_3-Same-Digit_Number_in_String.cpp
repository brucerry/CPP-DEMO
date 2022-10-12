// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string largestGoodInteger(string& num) {
    char c = 0;
    for (int i = 2; i < num.size(); i++) {
      if (num[i-2] == num[i] and num[i-1] == num[i])
        c = max(c, num[i]);
    }
    return c ? string(3, c) : "";
  }
};