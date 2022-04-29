// https://leetcode.com/problems/hand-of-straights/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize)
      return false;
    
    unordered_map<int, int> intCount;
    for (const int& val : hand)
      intCount[val]++;
    
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (const auto& [ val, _ ] : intCount)
      minHeap.emplace(val);
    
    while (minHeap.size()) {
      int smallestVal = minHeap.top();
      
      for (int num = smallestVal; num < smallestVal + groupSize; num++) {
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