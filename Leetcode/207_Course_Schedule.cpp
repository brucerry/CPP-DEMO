// https://leetcode.com/problems/course-schedule/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
  bool hasCycle(vector<int> *graph, int node, vector<int>& visited) {
    if (visited[node] == 2) return false;
    if (visited[node] == 1) return true;

    visited[node] = 1;

    for (auto neighbor : graph[node]) {
      if (hasCycle(graph, neighbor, visited)) return true;
    }

    visited[node] = 2;

    return false;
}

public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> graph[numCourses];
    for (auto courses : prerequisites) {
      int a = courses[1];
      int b = courses[0];
      graph[a].push_back(b);
    }
    
    vector<int> visited (numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
      if (hasCycle(graph, i, visited)) return false;
    }

    return true;
  }
};