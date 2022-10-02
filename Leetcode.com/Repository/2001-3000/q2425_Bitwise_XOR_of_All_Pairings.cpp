// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include <vector>
using namespace std;

// time: O(m + n)
// space: O(1)

class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int xor_n1 = 0, xor_n2 = 0;
    for (const int& n2 : nums2) {
      xor_n2 ^= n2;
    }
    for (const int& n1 : nums1) {
      xor_n1 ^= n1;
    }
    
    int len1 = nums1.size(), len2 = nums2.size();
    if (len1 % 2 == 0 and len2 % 2 == 0)
      return 0;
    
    if (len1 % 2 and len2 % 2)
      return xor_n1 ^ xor_n2;
    
    if (len1 % 2)
      return xor_n2;
    
    return xor_n1;
  }
};