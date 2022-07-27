// https://leetcode.com/problems/find-target-indices-after-sorting-array/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int targetCount = 0, lessCount = 0;
    for (const int& num : nums) {
      if (num < target)
        lessCount++;
      else if (num == target)
        targetCount++;
    }
    
    vector<int> indices (targetCount);
    iota(indices.begin(), indices.end(), lessCount);
    return indices;
  }
};