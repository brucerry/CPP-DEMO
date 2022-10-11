// https://leetcode.com/problems/count-number-of-ways-to-place-houses/

// time: O(n)
// space: O(1)

class Solution {
public:
  int countHousePlacements(int n) {
    int house = 1, empty = 1, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      int tmp = house;
      house = empty;
      empty = (tmp + empty) % mod;
    }
    return (long)empty * empty % mod;
  }
};