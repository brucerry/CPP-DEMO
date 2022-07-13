// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

#include <string>
using namespace std;

// time: O(n + k)
// space: O(1)

class Solution {
public:
  int getLucky(string& s, int k) {
    int sum = 0;
    for (const char& c : s) {
      int val = c - 'a' + 1;
      sum += val / 10 + val % 10;
    }
    
    while (--k and sum >= 10) {
      int tmp = 0;
      for (; sum; sum /= 10)
        tmp += sum % 10;
      sum = tmp;
    }
    
    return sum;
  }
};