// https://leetcode.com/problems/ugly-number/

#include <array>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool isUgly(int n) {
    if (n <= 0)
      return false;
    
    array<int, 3> factors { 2, 3, 5 };
    for (const int& f : factors) {
      while (n % f == 0)
        n /= f;
    }
    
    return n == 1;
  }
};