// https://leetcode.com/problems/factorial-trailing-zeroes/

// time: O(log(n) base 5)
// space: O(log(n) base 5)
class Recursive {
public:
  int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};

// time: O(log(n) base 5)
// space: O(1)
class Iterative {
public:
  int trailingZeroes(int n) {
    int result = 0;
    for (; n; n /= 5) {
      result += n / 5;
    }
    return result;
  }
};