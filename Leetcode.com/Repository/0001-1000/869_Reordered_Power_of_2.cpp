// https://leetcode.com/problems/reordered-power-of-2/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    long n_count = count(n);
    for (int i = 0; i < 32; i++) {
      if (n_count == count(1 << i))
        return true;
    }
    return false;
  }
  
private:
  long count(int n) {
    long result = 0;
    for (; n; n /= 10)
      result += pow(10, n % 10);
    return result;
  }
};