// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <vector>
using namespace std;

// time: O(n * log(sum(weights)))
// space: O(1)

class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int l = 0, r = 0;
    for (const int& weight : weights) {
      l = max(l, weight);
      r += weight;
    }
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (canShip(weights, days, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
  
private:
  bool canShip(vector<int>& weights, int days, int maxCapacity) {
    int needDay = 0, curCapacity = 0;
    for (const int& weight : weights) {
      if (weight > maxCapacity)
        return false;
      curCapacity += weight;
      if (curCapacity > maxCapacity) {
        curCapacity = weight;
        needDay++;
      }
    }
    return needDay + 1 <= days;
  }
};