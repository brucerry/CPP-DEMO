// https://leetcode.com/problems/basic-calculator-ii/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int calculate(string& s) {
    int n = s.length(), result = 0, lastNumber = 0, curNumber = 0, sign = '+';
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (isdigit(c))
        curNumber = (curNumber * 10) + (c - '0');
      
      if ((!isdigit(c) and !iswspace(c)) or i == n - 1) {
        if (sign == '+' or sign == '-') {
          result += lastNumber;
          lastNumber = sign == '+' ? curNumber : -curNumber;
        }
        else if (sign == '*')
          lastNumber *= curNumber;
        else if (sign == '/')
          lastNumber /= curNumber;

        curNumber = 0;
        sign = c;
      }
    }

    result += lastNumber;
    return result;
  }
};