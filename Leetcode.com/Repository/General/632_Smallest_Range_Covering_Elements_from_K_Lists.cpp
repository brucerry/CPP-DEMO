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
    int k = nums.size();
    
    int ansl = 0;
    int ansr = INT_MAX;
    int maxNum = INT_MIN;
    vector<int> next (k); // eg. next[1] = 5 means next position of nums[1] is index 5
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    
    for (int i = 0; i < k; i++) {
      minHeap.emplace(nums[i][0], i);
      maxNum = max(maxNum, nums[i][0]);
    }
    
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < nums[i].size(); j++) {
        auto [ _, min_i ] = minHeap.top();
        minHeap.pop();
        
        if (ansr - ansl > maxNum - nums[min_i][next[min_i]]) {
          ansr = maxNum;
          ansl = nums[min_i][next[min_i]];
        }
        
        next[min_i]++;
        if (next[min_i] == nums[min_i].size())
          return { ansl, ansr };
        
        minHeap.emplace(nums[min_i][next[min_i]], min_i);
        maxNum = max(maxNum, nums[min_i][next[min_i]]);
      }
    } 
    
    return { ansl, ansr };
  }
};