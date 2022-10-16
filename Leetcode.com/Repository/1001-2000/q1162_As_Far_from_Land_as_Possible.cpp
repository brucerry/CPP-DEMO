// https://leetcode.com/problems/as-far-from-land-as-possible/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();

    queue<pair<int, int>> queue;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c])
          queue.emplace(r, c);
      }
    }

    char moves[] { 0, 1, 0, -1, 0 };
    int dist = 0;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        auto [ r, c ] = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++) {
          int newr = r + moves[i], newc = c + moves[i+1];
          if (0 <= newr and newr < n and 0 <= newc and newc < n and grid[newr][newc] == 0) {
            grid[newr][newc] = 1;
            queue.emplace(newr, newc);
          }
        }
      }
      dist++;
    }

    return dist == 1 ? -1 : dist - 1;
  }
};