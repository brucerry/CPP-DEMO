// https://leetcode.com/problems/count-integers-with-even-digit-sum/

// time: O(log(num) base 10)
// space: O(1)

class Solution {
public:
  int countEven(int num) {
    int tmp = num, sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return (tmp - (sum & 1)) >> 1;
  }
};