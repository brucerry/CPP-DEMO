// https://leetcode.com/problems/integer-to-roman/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  string intToRoman(int num) {
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string strs[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    
    string result;
    for (int i = 0; i < sizeof(values) / sizeof(int); i++) {
      while (num >= values[i]) {
        num -= values[i];
        result += strs[i];
      }
    }
    
    return result;
  }
};