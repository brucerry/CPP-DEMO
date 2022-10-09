// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// s = size of spells
// p = size of potions
// time: O(p * log(p) + s * log(p))
// space: O(log(p)) for sorting

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    for (int& spell : spells) {
      long x = ceil(success / (double)spell);
      auto it = lower_bound(potions.begin(), potions.end(), x);
      spell = potions.end() - it;
    }
    return spells;
  }
};