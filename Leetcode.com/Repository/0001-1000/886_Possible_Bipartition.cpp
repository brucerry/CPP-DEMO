// https://leetcode.com/problems/possible-bipartition/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph (n + 1);
    for (const auto& dis : dislikes) {
      int a = dis[0], b = dis[1];
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

    vector<char> colors (n + 1, -1);
    for (int node = 1; node <= n; node++) {
      if (colors[node] == -1 and !assignColor(graph, colors, node, 1))
        return false;
    }
    return true;
  }

private:
  bool assignColor(vector<vector<int>>& graph, vector<char>& colors, int node, char color) {
    if (colors[node] != -1)
      return colors[node] == color;

    colors[node] = color;
    for (const int& neighbor : graph[node]) {
      if (!assignColor(graph, colors, neighbor, !color))
        return false;
    }
    return true;
  }
};