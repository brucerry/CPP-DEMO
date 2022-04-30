// https://leetcode.com/problems/last-stone-weight/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(1)

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;
    for (const int& stone : stones) {
      maxHeap.emplace(stone);
    }
    
    while (maxHeap.size() > 1) {
      int stone1 = maxHeap.top();
      maxHeap.pop();
      int stone2 = maxHeap.top();
      maxHeap.pop();
      
      if (stone1 > stone2)
        maxHeap.emplace(stone1 - stone2);
    }
    
    return maxHeap.size() ? maxHeap.top() : 0;
  }
};