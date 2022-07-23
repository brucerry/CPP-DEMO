// https://leetcode.com/problems/number-of-zero-filled-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long subarray = 0;
    int count = 0;
    for (const int& num : nums) {
      if (num)
        count = 0;
      else
        count++;
      subarray += count;
    }
    return subarray;
  }
};