// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> numSet (nums.begin(), nums.end());
    return numSet.count(0) ? numSet.size() - 1 : numSet.size();
  }
};