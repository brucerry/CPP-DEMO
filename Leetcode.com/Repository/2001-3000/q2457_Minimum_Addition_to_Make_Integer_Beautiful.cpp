// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/

// time: O(log(n) * log(n))
// space: O(1)

class Solution {
public:
  long long makeIntegerBeautiful(long long n, int target) {
    long org = n, multi = 1;
    while (sum(n) > target) {
      n = n / 10 + 1;
      multi *= 10;
    }
    return n * multi - org;
  }
  
private:
  int sum(long n) {
    int result = 0;
    while (n) {
      result += n % 10;
      n /= 10;
    }
    return result;
  }
};