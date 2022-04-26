// https://leetcode.com/problems/valid-perfect-square/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 1, right = num;
    
    while (left <= right) {
      long mid = left + ((right - left) >> 1);
      long ans = mid * mid;
      
      if (ans > num)
        right = mid - 1;
      else if (ans < num)
        left = mid + 1;
      else
        return true;
    }
    
    return false;
  }
};