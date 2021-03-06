// https://leetcode.com/problems/surrounded-regions/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (board[r][c] == 'O' and (r == 0 or r == rows - 1 or c == 0 or c == cols - 1))
          exploreO(board, r, c);
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (board[r][c] == 'O')
          board[r][c] = 'X';
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (board[r][c] == '*')
          board[r][c] = 'O';
      }
    }
  }
  
private:
  void exploreO(vector<vector<char>>& board, int r, int c) {
    if (r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or board[r][c] != 'O')
      return;
    
    board[r][c] = '*';
    
    exploreO(board, r+1, c);
    exploreO(board, r-1, c);
    exploreO(board, r, c+1);
    exploreO(board, r, c-1);
  }
};