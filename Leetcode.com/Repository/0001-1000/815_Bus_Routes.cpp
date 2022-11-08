// https://leetcode.com/problems/bus-routes/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    unordered_map<int, vector<int>> umap; // stop id, { bus ids }
    for (int busID = 0; busID < routes.size(); busID++) {
      for (const int& stopID : routes[busID]) {
        umap[stopID].emplace_back(busID);
      }
    }

    queue<int> queue; // stop id
    queue.emplace(source);

    unordered_set<int> visited { source };

    int buses = 0;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        int stopID = queue.front();
        queue.pop();
        if (stopID == target)
          return buses;
        for (const int& busID : umap[stopID]) {
          for (const int& stop : routes[busID]) {
            if (visited.count(stop) == 0) {
              visited.emplace(stop);
              queue.emplace(stop);
            }
          }
          routes[busID].clear();
        }
      }
      buses++;
    }

    return -1;
  }
};