// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size();
    
    auto [ minIt, maxIt ] = minmax_element(nums.begin(), nums.end());
    int minIndex = minIt - nums.begin();
    int maxIndex = maxIt - nums.begin();
    
    int leftToMax = maxIndex + 1;
    int rightToMax = n - maxIndex;
    int leftToMin = minIndex + 1;
    int rightToMin = n - minIndex;
    
    int removeMax = min(leftToMax, rightToMax);
    int removeMin = min(leftToMin, rightToMin);
    int removeBoth = min(max(leftToMin, leftToMax), max(rightToMin, rightToMax));
    
    return min(removeBoth, removeMax + removeMin);
  }
};