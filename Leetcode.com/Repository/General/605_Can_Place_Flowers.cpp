// https://leetcode.com/problems/can-place-flowers/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int empty = flowerbed[0] ? 0 : 1;

    for (int& flower : flowerbed) {
      if (flower) {
        n -= (empty - 1) / 2;
        empty = 0;
      }
      else {
        empty++;
      }
    }

    n -= empty / 2;

    return n <= 0;
  }
};