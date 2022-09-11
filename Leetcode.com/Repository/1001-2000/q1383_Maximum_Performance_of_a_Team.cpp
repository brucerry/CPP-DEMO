// https://leetcode.com/problems/maximum-performance-of-a-team/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + n * log(k))
// space: O(n + k)

class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> pairs (n); // efficiency[i], speed[i]
    for (int i = 0; i < n; i++) {
      pairs[i] = { efficiency[i], speed[i] };
    }
    sort(pairs.rbegin(), pairs.rend());
    
    priority_queue<int, vector<int>, greater<>> minHeap; // speed
    long result = 0, curSumSpeed = 0;
    for (const auto& [ eff, spd ] : pairs) {
      if (minHeap.size() == k) {
        curSumSpeed -= minHeap.top();
        minHeap.pop();
      }
      curSumSpeed += spd;
      minHeap.emplace(spd);
      result = max(result, eff * curSumSpeed);
    }
    
    return result % 1000000007;
  }
};