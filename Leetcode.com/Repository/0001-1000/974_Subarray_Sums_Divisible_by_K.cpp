// https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> count (k);
    count[0] = 1;
    
    int prefix = 0, subarray = 0;
    for (const int& num : nums) {
      prefix = (prefix + num % k + k) % k;
      subarray += count[prefix]++;
    }
    return subarray;
  }
};