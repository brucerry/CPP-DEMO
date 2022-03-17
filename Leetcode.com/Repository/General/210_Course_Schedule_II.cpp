// https://leetcode.com/problems/course-schedule-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;

    for (auto& courses : prerequisites) {
      graph[courses[1]].push_back(courses[0]);
    }

    unordered_map<int, int> numParents;

    for (int i = 0; i < numCourses; i++) {
      numParents[i] = 0;
    }

    for (auto& [ node, neighbors ] : graph) {
      for (int& neighbor : neighbors) {
        numParents[neighbor]++;
      }
    }

    vector<int> ready;
    for (auto& [ node, count ] : numParents) {
      if (count == 0) {
        ready.push_back(node);
      }
    }

    vector<int> result;

    while (ready.size()) {
      int node = ready.back();
      ready.pop_back();

      result.push_back(node);

      for (auto& neighbor : graph[node]) {
        if (--numParents[neighbor] == 0) {
          ready.push_back(neighbor);
        }
      }
    }

    return result.size() == numCourses ? result : vector<int>();
  }
};