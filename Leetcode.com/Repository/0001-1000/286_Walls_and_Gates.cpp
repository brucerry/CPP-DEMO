// https://leetcode.com/problems/walls-and-gates/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    int rows = rooms.size();
    int cols = rooms[0].size();

    queue<pair<int, int>> queue; // r, c
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (rooms[r][c] == 0)
          queue.emplace(r, c);
      }
    }

    vector<pair<int, int>> moves { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    int dist = 0;
    while (queue.size()) {
      int size = queue.size();

      while (size--) {
        auto [ r, c ] = queue.front();
        queue.pop();

        for (const auto& [ dr, dc ] : moves) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr and newr < rows and 0 <= newc and newc < cols and rooms[newr][newc] == INT_MAX) {
            rooms[newr][newc] = dist + 1;
            queue.emplace(newr, newc);
          }
        }
      }
      dist++;
    }
  }
};