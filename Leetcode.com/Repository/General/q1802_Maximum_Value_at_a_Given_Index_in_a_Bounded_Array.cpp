// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/

// time: O(log(maxSum))
// space: O(1)

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int l = 0, r = maxSum;
    while (l < r) {
      int m = l + ((r - l + 1) >> 1);
      if (canConstruct(n, index, maxSum, m))
        l = m;
      else
        r = m - 1;
    }
    return l + 1;
  }
  
private:
  bool canConstruct(int n, int index, int maxSum, int maxVal) {
    // peak value at 'index' = maxVal
    // arithmetic sequence on the left of 'index' with common difference = +1
    // arithmetic sequence on the right of 'index' with common difference = -1
    
    int leftmost = max(0, maxVal - index), rightmost = max(0, maxVal - (n - 1 - index));
    long leftAS = (long)(leftmost + maxVal) * (maxVal - leftmost + 1) >> 1;
    long rightAS = (long)(rightmost + maxVal) * (maxVal - rightmost + 1) >> 1;
    return leftAS + rightAS - maxVal <= maxSum;
  }
};