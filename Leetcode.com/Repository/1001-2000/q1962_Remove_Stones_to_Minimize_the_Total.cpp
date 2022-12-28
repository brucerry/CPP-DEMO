// https://leetcode.com/problems/remove-stones-to-minimize-the-total/

#include <vector>
#include <numeric>
#include <queue>
using namespace std;

// time: O(k * log(n) + n)
// space: O(n)

class Solution {
public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> maxHeap (piles.begin(), piles.end());
    int res = accumulate(piles.begin(), piles.end(), 0);
    while (k--) {
      int stone = maxHeap.top();
      maxHeap.pop();
      maxHeap.emplace(stone - stone / 2);
      res -= stone / 2;
    }
    return res;
  }
};