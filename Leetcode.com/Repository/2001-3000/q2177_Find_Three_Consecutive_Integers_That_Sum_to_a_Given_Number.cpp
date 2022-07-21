// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  vector<long long> sumOfThree(long long num) {
    if (num % 3)
      return {};
    
    long long x = num / 3;
    return { x - 1, x, x + 1 };
  }
};