// https://leetcode.com/problems/longest-cycle-in-a-graph/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)
class Method1 {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<pair<int, int>> distFrom (n, { -1, -1 }); // dist, from
    
    int longest = -1;
    for (int node = 0; node < n; node++) {
      for (int cur = node, dist = 0; cur != -1; cur = edges[cur]) {
        auto [ dist_cur, from ] = distFrom[cur];
        if (dist_cur == -1)
          distFrom[cur] = { dist++, node };
        else {
          if (from == node)
            longest = max(longest, dist - dist_cur);
          break;
        }
      }
    }
    
    return longest;
  }
};

// time: O(n)
// space: O(n)
class Method2 {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    vector<int> dists (n, -1);
    
    int longest = -1;
    for (int node = 0, dist = 0; node < n; node++) {
      int cur = node, curDist = dist;
      while (cur != -1 and dists[cur] == -1) {
        dists[cur] = dist++;
        cur = edges[cur];
      }
      if (cur != -1 and dists[cur] >= curDist)
        longest = max(longest, dist - dists[cur]);
    }
    
    return longest;
  }
};