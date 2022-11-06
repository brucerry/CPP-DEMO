// https://leetcode.com/problems/total-cost-to-hire-k-workers/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
#define LEFT 0
#define RIGHT 1

public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minheap; // cost, index, side
    int l = 0, r = n - 1;
    while (l < candidates and l <= r)
      minheap.emplace(costs[l], l++, LEFT);
    while (n - r <= candidates and l <= r)
      minheap.emplace(costs[r], r--, RIGHT);
    
    long result = 0;
    for (; k and minheap.size(); k--) {
      auto [ cost, i, side ] = minheap.top();
      minheap.pop();
      result += cost;
      if (l <= r) {
        if (side == LEFT)
          minheap.emplace(costs[l], l++, LEFT);
        else
          minheap.emplace(costs[r], r--, RIGHT);
      }
    }
    
    return result;
  }
};