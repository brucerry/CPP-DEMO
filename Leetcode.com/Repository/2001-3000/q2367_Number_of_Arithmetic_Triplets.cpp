// https://leetcode.com/problems/number-of-arithmetic-triplets/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    unordered_set<int> numSet (nums.begin(), nums.end());
    
    int triplets = 0;
    for (const int& num : nums) {
      if (numSet.count(num + diff) and numSet.count(num + diff * 2))
        triplets++;
    }
    return triplets;
  }
};