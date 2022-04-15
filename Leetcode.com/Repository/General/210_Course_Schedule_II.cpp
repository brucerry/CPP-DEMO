// https://leetcode.com/problems/course-schedule-ii/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph (numCourses);
    vector<int> parentCount (numCourses, 0);
    
    for (const auto& p : prerequisites) {
      graph[p[1]].emplace_back(p[0]);
      parentCount[p[0]]++;
    }
    
    vector<int> ready;
    
    for (int node = 0; node < numCourses; node++) {
      if (parentCount[node] == 0)
        ready.emplace_back(node);
    }
    
    vector<int> ans;
    
    while (ready.size()) {
      int node = ready.back();
      ready.pop_back();
      
      ans.emplace_back(node);
      
      for (const int& neighbor : graph[node]) {
        if (--parentCount[neighbor] == 0) {
          ready.emplace_back(neighbor);
        }
      }
    }
    
    return ans.size() == numCourses ? ans : vector<int>();
  }
};