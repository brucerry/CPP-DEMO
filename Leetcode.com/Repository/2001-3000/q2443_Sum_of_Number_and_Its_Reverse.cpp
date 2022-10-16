// https://leetcode.com/problems/sum-of-number-and-its-reverse/

// rev = log(num) base 10
// time: O(num * rev)
// space: O(1)

class Solution {
public:
  bool sumOfNumberAndReverse(int num) {
    for (int i = 0; i <= num; i++) {
      if (i + rev(i) == num)
        return true;
    }
    return false;
  }
  
private:
  int rev(int n) {
    int result = 0;
    for (; n; n /= 10) {
      result = result * 10 + n % 10;
    }
    return result;
  }
};