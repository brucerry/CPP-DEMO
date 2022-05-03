// https://leetcode.com/problems/water-bottles/

// n = numBottles
// m = numExchange
// time: O(log(n) based m)
// space: O(1)

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int drinkCount = numBottles;
    int remain = numBottles;
    
    while (remain >= numExchange) {
      int full = remain / numExchange;
      int empty = remain % numExchange;
      
      drinkCount += full;
      remain = full + empty;
    }
    
    return drinkCount;
  }
};