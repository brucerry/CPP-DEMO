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
    int maxIndex = maxIt - nums.begin();
    int minIndex = minIt - nums.begin();
    
    int removeMaxFromLeft = maxIndex + 1;
    int removeMaxFromRight = n - maxIndex;
    int removeMinFromLeft = minIndex + 1;
    int removeMinFromRight = n - minIndex;
    
    int fromLeft = max(removeMaxFromLeft, removeMinFromLeft);
    int fromRight = max(removeMaxFromRight, removeMinFromRight);
    int fromBoth = min(removeMaxFromLeft, removeMinFromLeft) + min(removeMaxFromRight, removeMinFromRight);
    
    return min({ fromLeft, fromRight, fromBoth });
  }
};