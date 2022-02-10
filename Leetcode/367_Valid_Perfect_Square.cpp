// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:

  // binary search
  // time: O(log(n))
  // space: O(1)
  bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long ans = mid * mid;
      if (ans < num) left = mid + 1; 
      else if (ans > num) right = mid - 1;
      else return true;
    }
    return false;
  }
};