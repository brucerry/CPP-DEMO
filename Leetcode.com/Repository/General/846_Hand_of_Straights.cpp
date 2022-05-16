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
    
    unordered_map<int, int> numCount;
    for (const int& num : hand)
      numCount[num]++;
    
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (const auto& [ num, _ ] : numCount)
      minHeap.emplace(num);
    
    while (minHeap.size()) {
      int num = minHeap.top();
      
      for (int val = num; val < num + groupSize; val++) {
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