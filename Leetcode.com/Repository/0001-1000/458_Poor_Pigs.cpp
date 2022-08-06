// https://leetcode.com/problems/poor-pigs/

#include <cmath>

// time: O(1)
// space: O(1)
class Logarithm {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int base = minutesToTest / minutesToDie + 1;
    return ceil(log(buckets) / log(base));
  }
};

// time: O(log(buckets))
// space: O(1)
class PowerTo {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int base = minutesToTest / minutesToDie + 1, pig = 0;
    while (pow(base, pig) < buckets)
      pig++;
    return pig;
  }
};