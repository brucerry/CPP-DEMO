// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <vector>
#include <queue>
using namespace std;

// n = # of all elements in lists
// k = # of list
// time: O(n * log(k))
// space: O(k)

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int rows = nums.size();
    
    int ansl = 0, ansr = INT_MAX;
    int maxNum = INT_MIN;
    vector<int> nextIndex (rows);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // val, row index
    for (int r = 0; r < rows; r++) {
      minHeap.emplace(nums[r][0], r);
      maxNum = max(maxNum, nums[r][0]);
    }
    
    for (const auto& row : nums) {
      for (const int& num : row) {
        auto [ _, r ] = minHeap.top();
        minHeap.pop();
        
        if (ansr - ansl > maxNum - nums[r][nextIndex[r]]) {
          ansr = maxNum;
          ansl = nums[r][nextIndex[r]];
        }
        
        nextIndex[r]++;
        if (nextIndex[r] == nums[r].size())
          return { ansl, ansr };
        
        minHeap.emplace(nums[r][nextIndex[r]], r);
        maxNum = max(maxNum, nums[r][nextIndex[r]]);
      }
    }
    
    return { ansl, ansr };
  }
};