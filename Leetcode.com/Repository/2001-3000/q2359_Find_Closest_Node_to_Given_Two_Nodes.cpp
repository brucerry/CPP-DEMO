// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dists_1 (n, -1), dists_2 (n, -1);
    collectDistance(edges, node1, 0, dists_1);
    collectDistance(edges, node2, 0, dists_2);
    
    int result = -1, maxDist = INT_MAX;
    for (int node = 0; node < n; node++) {
      if (min(dists_1[node], dists_2[node]) > -1 and max(dists_1[node], dists_2[node]) < maxDist) {
        result = node;
        maxDist = max(dists_1[node], dists_2[node]);
      }
    }
    
    return result;
  }
  
private:
  void collectDistance(vector<int>& edges, int node, int dist, vector<int>& dists) {
    while (node != -1 and dists[node] == -1) {
      dists[node] = dist++;
      node = edges[node];
    }
  }
};