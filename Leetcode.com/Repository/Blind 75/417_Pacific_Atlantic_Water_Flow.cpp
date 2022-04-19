// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
private:
  void traverse(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<vector<char>>& visited) {
    if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || prevHeight > heights[r][c] || visited[r][c])
      return;
    
    visited[r][c] = 1;
    
    traverse(heights, r+1, c, heights[r][c], visited);
    traverse(heights, r-1, c, heights[r][c], visited);
    traverse(heights, r, c+1, heights[r][c], visited);
    traverse(heights, r, c-1, heights[r][c], visited);
  }
  
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    
    vector<vector<char>> visitedAtlantic (rows, vector<char>(cols, 0));
    vector<vector<char>> visitedPacific = visitedAtlantic;
    
    for (int r = 0; r < rows; r++) {
      traverse(heights, r, 0, -1, visitedPacific);
      traverse(heights, r, cols - 1, -1, visitedAtlantic);
    }
    
    for (int c = 0; c < cols; c++) {
      traverse(heights, 0, c, -1, visitedPacific);
      traverse(heights, rows - 1, c, -1, visitedAtlantic);
    }
    
    vector<vector<int>> result;
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (visitedAtlantic[r][c] && visitedPacific[r][c]) {
          result.push_back({ r, c });
        }
      }
    }
    
    return result;
  }
};