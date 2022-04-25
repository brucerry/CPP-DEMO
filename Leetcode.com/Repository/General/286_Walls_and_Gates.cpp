// https://leetcode.com/problems/walls-and-gates/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    queue<pair<int, int>> queue; // r, c

    for (int r = 0; r < rooms.size(); r++) {
      for (int c = 0; c < rooms[0].size(); c++) {
        if (!rooms[r][c])
          queue.emplace(r, c);
      }
    }

    int dist = 0;

    vector<pair<int, int>> dirs { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    while (queue.size()) {
      int size = queue.size();

      while (size--) {
        auto [ r, c ] = queue.front();
        queue.pop();

        for (const auto& [ dr, dc ] : dirs) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr and newr < rooms.size() and 0 <= newc and newc < rooms[0].size() and rooms[newr][newc] == INT_MAX) {
            queue.emplace(newr, newc);
            rooms[newr][newc] = dist + 1;
          }
        }
      }

      dist++;
    }
  }
};