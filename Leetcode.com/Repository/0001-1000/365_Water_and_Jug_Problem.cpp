// https://leetcode.com/problems/water-and-jug-problem/

#include <numeric>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    if (jug1Capacity + jug2Capacity < targetCapacity)
      return false;
    return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
  }
};