// https://leetcode.com/problems/happy-number/

// time: O(1)
// space: O(1)

class Solution {
private:
  int sumOfSquare(int num) {
    int sum = 0;
    while (num) {
      int d = num % 10;
      sum += d * d;
      num /= 10;
    }
    return sum;
  }

public:
  bool isHappy(int n) {
    int slower = sumOfSquare(n);
    int faster = sumOfSquare(sumOfSquare(n));

    do {
      if (faster == 1) return true;
      slower = sumOfSquare(slower);
      faster = sumOfSquare(sumOfSquare(faster));
    } while (slower != faster);

    return false;
  }
};