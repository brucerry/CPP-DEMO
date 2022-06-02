// https://leetcode.com/problems/reverse-bits/

// time: O(1)
// space: O(1)

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    for (int i = 0; i < 32; i++) {
      if ((n >> i) & 1) {
        result |= (1 << (31 - i));
      }
    }
    
    return result;
  }
};