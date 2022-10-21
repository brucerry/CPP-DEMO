// https://leetcode.com/problems/time-needed-to-inform-all-employees/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    int result = 0;
    for (int node = 0; node < n; node++) {
      result = max(result, traverse(manager, informTime, node));
    }
    return result;
  }

private:
  int traverse(vector<int>& manager, vector<int>& informTime, int node) {
    if (manager[node] != -1) {
      informTime[node] += traverse(manager, informTime, manager[node]);
      manager[node] = -1;
    }
    return informTime[node];
  }
};