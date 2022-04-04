// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <vector>
using namespace std;

// Union Find
// time: O(n + e)
// space: O(n)

class Solution {
private:
  int findRootParent(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }

  int unionNodes(vector<int>& parents, vector<int>& ranks, int node1, int node2) {
    int parent1 = findRootParent(parents, node1);
    int parent2 = findRootParent(parents, node2);

    if (parent1 == parent2) return 0;

    if (ranks[parent1] > ranks[parent2]) {
      parents[parent2] = parent1;
      ranks[parent1] += ranks[parent2];
    }
    else {
      parents[parent1] = parent2;
      ranks[parent2] += ranks[parent1];
    }
    return 1;
  }

public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parents (n);
    vector<int> ranks (n, 1);

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      
      n -= unionNodes(parents, ranks, node1, node2);
    }

    return n;
  }
};