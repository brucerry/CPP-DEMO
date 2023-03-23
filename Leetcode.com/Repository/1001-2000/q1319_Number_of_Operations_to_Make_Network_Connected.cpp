// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <vector>
using namespace std;

// Union-Find solution
// time: O(n + e)
// space: O(n)

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() + 1)
            return -1;

        vector<int> parents (n);
        for (int node = 0; node < n; node++) {
            parents[node] = node;
        }
        for (const auto& c : connections) {
            n -= unionFind(parents, c[0], c[1]);
        }
        return n - 1;
    }

private:
    int unionFind(vector<int>& parents, int node1, int node2) {
        int par1 = find(parents, node1);
        int par2 = find(parents, node2);
        if (par1 == par2)
            return 0;
        parents[par1] = par2;
        return 1;
    }

    int find(vector<int>& parents, int node) {
        return node == parents[node] ? node : parents[node] = find(parents, parents[node]);
    }
};

// DFS solution
// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1)
      return -1;

    vector<vector<int>> graph (n);
    for (const auto& conn : connections) {
      int u = conn[0], v = conn[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    vector<char> visited (n);
    int groups = 0;
    for (int node = 0; node < n; node++) {
      groups += traverse(graph, visited, node);
    }

    return groups - 1;
  }

private:
  bool traverse(vector<vector<int>>& graph, vector<char>& visited, int node) {
    if (visited[node])
      return false;
    visited[node] = true;

    for (const int& neighbor : graph[node]) {
      traverse(graph, visited, neighbor);
    }

    return true;
  }
};