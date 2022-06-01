// https://leetcode.com/problems/course-schedule/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n)

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph (numCourses);
    for (const auto& p : prerequisites) {
      int from = p[1];
      int to = p[0];
      graph[from].emplace_back(to);
    }
    
    vector<char> visitState (numCourses); // 0: not visited, 1: visiting, 2: visited
    for (int node = 0; node < numCourses; node++) {
      if (hasCycle(graph, node, visitState))
        return false;
    }
    
    return true;
  }
  
private:
  bool hasCycle(vector<vector<int>>& graph, int node, vector<char>& visitState) {
    if (visitState[node] == 1)
      return true;
    
    if (visitState[node] == 2)
      return false;
    
    visitState[node] = 1;
    
    for (const int& neighbor : graph[node]) {
      if (hasCycle(graph, neighbor, visitState))
        return true;
    }
    
    visitState[node] = 2;
    
    return false;
  }
};