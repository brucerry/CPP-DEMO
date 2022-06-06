// https://leetcode.com/problems/happy-number/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool isHappy(int n) {
    int slow = cal(n), fast = cal(cal(n));
    while (slow != fast) {
      slow = cal(slow);
      fast = cal(cal(fast));
    }
    return slow == 1;
  }
  
private:
  int cal(int n) {
    int result = 0;
    while (n) {
      int x = n % 10;
      result += x * x;
      n /= 10;
    }
    return result;
  }
};