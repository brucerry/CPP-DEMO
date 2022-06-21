// https://leetcode.com/problems/course-schedule-ii/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> parentCount (numCourses);
    vector<vector<int>> graph (numCourses);
    for (const auto& pre : prerequisites) {
      int from = pre[1];
      int to = pre[0];
      graph[from].emplace_back(to);
      parentCount[to]++;
    }
    
    vector<int> ready;
    for (int node = 0; node < numCourses; node++) {
      if (parentCount[node] == 0)
        ready.emplace_back(node);
    }
    
    vector<int> coursesOrder;
    while (ready.size()) {
      int node = ready.back();
      ready.pop_back();
      
      coursesOrder.emplace_back(node);
      
      for (const int& neighbor : graph[node]) {
        if (--parentCount[neighbor] == 0)
          ready.emplace_back(neighbor);
      }
    }
    
    return coursesOrder.size() == numCourses ? coursesOrder : vector<int>();
  }
};