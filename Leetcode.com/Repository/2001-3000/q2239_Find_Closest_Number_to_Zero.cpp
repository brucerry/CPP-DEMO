// https://leetcode.com/problems/find-closest-number-to-zero/

#include <vector>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    int result = INT_MIN, dist = INT_MAX;
    for (const int& num : nums) {
      if (abs(num) < dist or (abs(num) == dist and num > result)) {
        dist = abs(num);
        result = num;
      }
    }
    return result;
  }
};