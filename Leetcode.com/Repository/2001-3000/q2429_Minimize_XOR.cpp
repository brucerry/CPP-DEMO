// https://leetcode.com/problems/minimize-xor/

// time: O(30)
// space: O(1)

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int numberOfBits = __builtin_popcount(num2);
    
    int x = 0, mask = 1 << 30;
    while (numberOfBits and mask) {
      if (num1 & mask) {
        x |= mask;
        numberOfBits--;
      }
      mask >>= 1;
    }
    
    mask = 1;
    while (numberOfBits and mask < (1 << 30)) {
      if ((num1 & mask) == 0) {
        x |= mask;
        numberOfBits--;
      }
      mask <<= 1;
    }
    
    return x;
  }
};