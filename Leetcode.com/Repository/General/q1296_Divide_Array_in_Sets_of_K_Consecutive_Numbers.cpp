// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k)
      return false;
    
    unordered_map<int, int> intCount;
    for (const int& val : nums)
      intCount[val]++;
    
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (const auto& [ num, _ ] : intCount)
      minHeap.emplace(num);
    
    while (minHeap.size()) {
      int smallestVal = minHeap.top();
      
      for (int num = smallestVal; num < smallestVal + k; num++) {
        if (intCount.count(num) == 0)
          return false;
        
        if (--intCount[num] == 0) {
          if (num != minHeap.top())
            return false;
          minHeap.pop();
        }
      }
    }
    
    return true;
  }
};