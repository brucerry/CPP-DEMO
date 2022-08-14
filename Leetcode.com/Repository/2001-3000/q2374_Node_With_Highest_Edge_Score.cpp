// https://leetcode.com/problems/node-with-highest-edge-score/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int edgeScore(vector<int>& edges) {
    int n = edges.size();
    vector<long> scores (n);
    
    for (int node = 0; node < n; node++) {
      int neighbor = edges[node];
      scores[neighbor] += node;
    }
    
    return max_element(scores.begin(), scores.end()) - scores.begin();
  }
};