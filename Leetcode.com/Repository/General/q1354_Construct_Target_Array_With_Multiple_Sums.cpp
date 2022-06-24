// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  bool isPossible(vector<int>& target) {
    priority_queue<int> maxHeap;
    long sum = 0;
    for (const int& num : target) {
      sum += num;
      maxHeap.emplace(num);
    }
    
    while (true) {
      int val = maxHeap.top();
      maxHeap.pop();
      
      long remain = sum - val;
      
      if (val == 1 or remain == 1)
        return true;
      if (val < remain or remain == 0 or val % remain == 0)
        return false;
      
      val %= remain;
      sum = remain + val;
      maxHeap.emplace(val);
    }
  }
};