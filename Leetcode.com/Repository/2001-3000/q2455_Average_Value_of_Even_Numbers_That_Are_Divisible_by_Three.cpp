// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int averageValue(vector<int>& nums) {
    int sum = 0, size = 0;
    for (const int& num : nums) {
      // same as
      // if (num % 6 == 0)
      if (num % 2 == 0 and num % 3 == 0)
        sum += num, size++;
    }
    return size == 0 ? 0 : sum / size;
  }
};