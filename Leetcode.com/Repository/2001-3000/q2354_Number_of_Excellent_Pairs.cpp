// https://leetcode.com/problems/number-of-excellent-pairs/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long countExcellentPairs(vector<int>& nums, int k) {
    unordered_set<int> numSet (nums.begin(), nums.end());
    
    int bitsCount[30] = {};
    for (const int& num : numSet)
      bitsCount[__builtin_popcount(num)]++;
    
    long long pairs = 0;
    for (int bits1 = 1; bits1 < 30; bits1++) {
      for (int bits2 = 1; bits2 < 30; bits2++) {
        if (bits1 + bits2 >= k)
          pairs += bitsCount[bits1] * bitsCount[bits2];
      }
    }
    
    return pairs;
  }
};