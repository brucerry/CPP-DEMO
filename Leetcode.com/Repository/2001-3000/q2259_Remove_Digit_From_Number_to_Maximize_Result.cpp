// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string removeDigit(string& number, char digit) {
    int last = -1, n = number.size();
    for (int i = 0; i < n; i++) {
      if (number[i] == digit) {
        last = i;
        if (i + 1 < n and number[i] < number[i+1])
          return number.erase(i, 1);
      }
    }
    return number.erase(last, 1);
  }
};