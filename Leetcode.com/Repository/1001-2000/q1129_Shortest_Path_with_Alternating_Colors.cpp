// https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
#define RED 0
#define BLUE 1

public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<int> graph[2][101];
    for (const auto& edge : redEdges)
      graph[RED][edge[0]].emplace_back(edge[1]);
    for (const auto& edge : blueEdges)
      graph[BLUE][edge[0]].emplace_back(edge[1]);

    int dist[2][101];
    fill(begin(dist[RED]), end(dist[RED]), INT_MAX);
    fill(begin(dist[BLUE]), end(dist[BLUE]), INT_MAX);
    traverse(graph, dist, 0, 0, RED);
    traverse(graph, dist, 0, 0, BLUE);

    vector<int> result (n);
    for (int node = 0; node < n; node++) {
      int min_dist = min(dist[RED][node], dist[BLUE][node]);
      result[node] = min_dist == INT_MAX ? -1 : min_dist;
    }

    return result;
  }

private:
  void traverse(vector<int> (*graph)[101], int (*dist)[101], int node, int d, int color) {
    if (dist[color][node] > d) {
      dist[color][node] = d;

      for (const int& neighbor : graph[!color][node]) {
        traverse(graph, dist, neighbor, d + 1, !color);
      }
    }
  }
};