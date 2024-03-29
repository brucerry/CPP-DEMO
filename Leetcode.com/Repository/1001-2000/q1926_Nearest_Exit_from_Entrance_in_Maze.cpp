// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int rows = maze.size(), cols = maze[0].size();

    queue<pair<int, int>> queue; // r, c
    queue.emplace(entrance[0], entrance[1]);
    maze[entrance[0]][entrance[1]] = '+';
    
    char moves[] { 0, 1, 0, -1, 0 };

    int steps = 0;
    while (int size = queue.size()) {
      for (; size; size--) {
        auto [ r, c ] = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++) {
          int newr = r + moves[i], newc = c + moves[i+1];
          if (min(newr, newc) >= 0 and newr < rows and newc < cols and maze[newr][newc] == '.') {
            if (min(newr, newc) == 0 or newr == rows - 1 or newc == cols - 1)
              return steps + 1;
            maze[newr][newc] = '+';
            queue.emplace(newr, newc);
          }
        }
      }
      steps++;
    }

    return -1;
  }
};