// https://leetcode.com/problems/keys-and-rooms/

#include <vector>
#include <bitset>
using namespace std;

// time: O(n)
// space: O(n^2)

class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    
    vector<vector<int>> graph (n);
    for (int node = 0; node < n; node++) {
      for (const int& neighbor : rooms[node]) {
        graph[node].emplace_back(neighbor);
      }
    }

    bitset<1001> visited;
    return n == traverse(graph, visited, 0);
  }

private:
  int traverse(vector<vector<int>>& graph, bitset<1001>& visited, int node) {
    if (visited[node])
      return 0;
    visited[node] = 1;

    int visitedCount = 1;
    for (const int& neighbor : graph[node]) {
      visitedCount += traverse(graph, visited, neighbor);
    }

    return visitedCount;
  }
};