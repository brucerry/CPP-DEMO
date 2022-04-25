// https://leetcode.com/problems/happy-number/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool isHappy(int n) {
    int slow = sumOfSquare(n);
    int fast = sumOfSquare(sumOfSquare(n));
    
    while (slow != fast) {
      slow = sumOfSquare(slow);
      fast = sumOfSquare(sumOfSquare(fast));
    }
    
    return fast == 1;
  }
  
private:
  int sumOfSquare(int n) {
    int sum = 0;
    while (n) {
      int d = n % 10;
      sum += d * d;
      n /= 10;
    }
    return sum;
  }
};