// https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool digitCount(string& num) {
    int counts[10] {};
    for (const char& c : num) {
      counts[c - '0']++;
    }

    for (int i = 0; i < num.size(); i++) {
      if (counts[i] != num[i] - '0')
        return false;
    }

    return true;
  }
};