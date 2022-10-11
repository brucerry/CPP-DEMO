// https://leetcode.com/problems/maximum-xor-after-operations/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maximumXOR(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_or<>());
  }
};