// https://leetcode.com/problems/course-schedule/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n)

class Solution {
private:
  bool hasCycle(vector<vector<int>>& graph, int node, vector<int>& visitStates) {
    if (visitStates[node] == 1) return true;
    if (visitStates[node] == 2) return false;
    
    visitStates[node] = 1;
    
    for (const int& neighbor : graph[node]) {
      if (hasCycle(graph, neighbor, visitStates)) return true;
    }
    
    visitStates[node] = 2;
    
    return false;
  }
  
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph (numCourses, vector<int>());
    
    for (const auto& courses : prerequisites) {
      graph[courses[1]].emplace_back(courses[0]);
    }
    
    vector<int> visitStates (numCourses, 0); // 1: visiting, 2: visited
    
    for (int node = 0; node < numCourses; node++) {
      if (graph[node].size() && hasCycle(graph, node, visitStates)) return false;
    }
    
    return true;
  }
};