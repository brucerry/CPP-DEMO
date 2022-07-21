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
    
    unordered_map<int, int> numCount;
    for (const int& num : nums)
      numCount[num]++;
    
    priority_queue<int, vector<int>, greater<>> minHeap; // num
    for (const auto& [ num, _ ] : numCount)
      minHeap.emplace(num);
    
    while (minHeap.size()) {
      int num = minHeap.top();
      
      for (int val = num; val < num + k; val++) {
        if (numCount.count(val) == 0)
          return false;
        
        if (--numCount[val] == 0) {
          if (val != minHeap.top())
            return false;
          minHeap.pop();
        }
      }
    }
    
    return true;
  }
};