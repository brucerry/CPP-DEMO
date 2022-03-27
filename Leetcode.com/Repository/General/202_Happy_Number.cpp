// https://leetcode.com/problems/happy-number/

#include <unordered_set>
using namespace std;

// time: O(1)
// space: O(n)

class Solution {
private:
  int sumOfSquare(int num) {
    int sum = 0;
    while (num) {
      int d = num % 10;
      sum += d * d;
      num /= 10;
    }
    return sum;
  }

public:
  bool isHappy(int n) {
    unordered_set<int> visited;

    while (visited.count(n) == 0) {
      visited.insert(n);
      n = sumOfSquare(n);
      if (n == 1) return true;
    }

    return false;
  }
};