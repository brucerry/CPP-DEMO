// https://leetcode.com/problems/is-graph-bipartite/

#include <vector>
#include <cstring>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    char n = graph.size(), colors[100];
    memset(colors, -1, sizeof(colors));
    for (char node = 0; node < n; node++) {
      if (colors[node] == -1 and !coloring(graph, node, colors, 0))
        return false;
    }
    return true;
  }

private:
  bool coloring(vector<vector<int>>& graph, char node, char* colors, char clr) {
    if (colors[node] != -1)
      return colors[node] == clr;
    colors[node] = clr;
    for (const char& neighbor : graph[node]) {
      if (!coloring(graph, neighbor, colors, !clr))
        return false;
    }
    return true;
  }
};