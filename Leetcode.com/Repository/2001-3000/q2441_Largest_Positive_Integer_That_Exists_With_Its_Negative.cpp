// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

#include <vector>
#include <bitset>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int findMaxK(vector<int>& nums) {
    int maxValue = -1;
    bitset<2001> mask;
    
    for (const int& num : nums) {
      mask[1000 + num] = 1;
      if (mask[1000 - num] and mask[1000 + num] and abs(num) > maxValue)
        maxValue = abs(num);
    }
    
    return maxValue;
  }
};