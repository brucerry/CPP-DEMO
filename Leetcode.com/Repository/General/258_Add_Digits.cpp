// https://leetcode.com/problems/add-digits/

// time: O(1)
// space: O(1)

class Solution {
public:
  int addDigits(int num) {
    if (num == 0)
      return 0;
    int result = num % 9;
    return result ? result : 9;
  }
};