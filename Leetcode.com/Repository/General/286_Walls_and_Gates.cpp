// https://leetcode.com/problems/walls-and-gates/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    queue<tuple<int, int, int>> queue;

    for (int r = 0; r < rooms.size(); r++) {
      for (int c = 0; c < rooms[0].size(); c++) {
        if (rooms[r][c] == 0)
          queue.emplace(r, c, 0);
      }
    }

    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    while (queue.size()) {
      int len = queue.size();

      while (len--) {
        auto [ r, c, dist ] = queue.front();
        queue.pop();
        
        for (const auto& [ dr, dc ] : moves) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr && newr < rooms.size() && 0 <= newc && newc < rooms[0].size() && rooms[newr][newc] == INT_MAX) {
            rooms[newr][newc] = dist + 1;
            queue.emplace(newr, newc, rooms[newr][newc]);
          }
        }
      }
    }
  }
};