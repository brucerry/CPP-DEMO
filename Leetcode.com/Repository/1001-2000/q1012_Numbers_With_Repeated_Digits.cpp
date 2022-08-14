// https://leetcode.com/problems/numbers-with-repeated-digits/

#include <string>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int numDupDigitsAtMostN(int n) {
    string num = to_string(n + 1);
    
    int count = 0, len = num.length();
    for (int i = 1; i < len; i++) {
      count += 9 * cal(9, i - 1);
    }
    
    int16_t usedMask = 0;
    for (int i = 0; i < len; i++) {
      for (int j = !i; j < num[i] - '0'; j++) {
        if (!(usedMask & (1 << j)))
          count += cal(9 - i, len - i - 1);
      }
      if (usedMask & (1 << (num[i] - '0')))
        break;
      usedMask |= (1 << (num[i] - '0'));
    }
    
    return n - count;
  }
  
private:
  int cal(int m, int n) { // return number of permutation P(m, n) = m! / (m - n)!
    int result = 1;
    while (n--)
      result *= m--;
    return result;
  }
};