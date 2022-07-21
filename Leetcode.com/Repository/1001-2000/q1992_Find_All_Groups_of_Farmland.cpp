// https://leetcode.com/problems/find-all-groups-of-farmland/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)
class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int rows = land.size();
    int cols = land[0].size();
    
    vector<vector<int>> farmland;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (land[r][c]) {
          int x, y;
          for (x = r; x < rows and land[x][c]; x++) {
            for (y = c; y < cols and land[x][y]; y++) {
              land[x][y] = 0;
            }
          }
          farmland.push_back({ r, c, x - 1, y - 1 });
        }
      }
    }
    
    return farmland;
  }
};

// time: O(r * c)
// space: O(1)
class MarkColumnsJump {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int rows = land.size();
    int cols = land[0].size();
    
    vector<vector<int>> farmland;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (land[r][c] == 1) {
          int x = r, y = c;
          while (y < cols and land[r][y])
            y++;
          while (x < rows and land[x][c]) {
            land[x][c] = y - c + 1;
            x++;
          }
          farmland.push_back({ r, c, x - 1, y - 1 });
        }
        if (land[r][c] > 1)
          c += land[r][c] - 1;
      }
    }
    
    return farmland;
  }
};