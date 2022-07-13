// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/

// time: O(1)
// space: O(1)

class Solution {
public:
  int minimumNumbers(int num, int k) {
    if (num == 0)
      return 0;
    
    for (int size = 1; size <= 10 and size * k <= num; size++) {
      if ((num - size * k) % 10 == 0)
        return size;
    }
    return -1;
  }
};