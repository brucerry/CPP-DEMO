// https://leetcode.com/problems/maximum-69-number/

// time: O(log(num))
// space: O(1)

class Solution {
public:
  int maximum69Number (int num) {
    num = rev(num, 0);
    return rev(num, 1);
  }

private:
  int rev(int n, int quota) {
    int result = 0;
    while (n) {
      int d = n % 10;
      if (d == 6 and quota) {
        quota = 0;
        d = 9;
      }
      result = result * 10 + d;
      n /= 10;
    }
    return result;
  }
};