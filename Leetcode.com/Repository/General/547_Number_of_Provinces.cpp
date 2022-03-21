// https://leetcode.com/problems/number-of-provinces/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
private:
  int findParent(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }

  int unionNodes(vector<int>& parents, vector<int>& ranks, int node1, int node2) {
    int parent1 = findParent(parents, node1);
    int parent2 = findParent(parents, node2);

    if (parent1 == parent2) return 0;

    if (ranks[parent1] < ranks[parent2]) {
      parents[parent1] = parent2;
      ranks[parent2] += ranks[parent1];
    }
    else {
      parents[parent2] = parent1;
      ranks[parent1] += ranks[parent2];
    }

    return 1;
  }

public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    const int n = isConnected.size();

    vector<int> parents (n);
    vector<int> ranks (n, 1);

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    
    int ans = n;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (r != c && isConnected[r][c]) {
          ans -= unionNodes(parents, ranks, r, c);
        }
      }
    }

    return ans;
  }
};