// https://leetcode.com/problems/single-number-iii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    long twins = 0;
    for (const int& num : nums)
      twins ^= num;
    
    twins &= -twins;
    
    vector<int> result { 0, 0 };
    for (const int& num : nums) {
      if (twins & num) {
        result[1] ^= num;
      }
      else {
        result[0] ^= num;
      }
    }
    
    return result;
  }
};