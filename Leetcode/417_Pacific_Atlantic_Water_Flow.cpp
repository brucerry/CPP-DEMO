// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
using namespace std;

class Solution {
private:
  void dfs(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<vector<bool>>& visited) {
    if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) return;
    if (prevHeight > heights[r][c]) return;
    if (visited[r][c]) return;
    visited[r][c] = true;

    dfs(heights, r + 1, c, heights[r][c], visited);
    dfs(heights, r, c + 1, heights[r][c], visited);
    dfs(heights, r - 1, c, heights[r][c], visited);
    dfs(heights, r, c - 1, heights[r][c], visited);
  }

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<bool>> visitedPacific (row, vector<bool>(col, false));
    vector<vector<bool>> visitedAtlantic (row, vector<bool>(col, false));

    for (int r = 0; r < row; r++) {
      dfs(heights, r, 0, -1, visitedPacific);
      dfs(heights, r, col - 1, -1, visitedAtlantic);
    }

    for (int c = 0; c < col; c++) {
      dfs(heights, 0, c, -1, visitedPacific);
      dfs(heights, row - 1, c, -1, visitedAtlantic);
    }

    vector<vector<int>> result;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (visitedAtlantic[r][c] && visitedPacific[r][c]) {
          result.push_back({r, c});
        }
      }
    }

    return result;
  }
};