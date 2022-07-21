// https://leetcode.com/problems/game-of-life/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
  /**********************
    original new  code
        0     0    0
        1     0    1
        0     1    2
        1     1    3
  **********************/
public:
  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int live = countLives(board, r, c);
        if (board[r][c] == 0 and live == 3)
          board[r][c] = 2;
        else if (board[r][c] and 2 <= live and live <= 3)
          board[r][c] = 3;
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (board[r][c] == 1)
          board[r][c] = 0;
        else if (board[r][c] == 2 or board[r][c] == 3)
          board[r][c] = 1;
      }
    }
  }
  
private:
  int countLives(vector<vector<int>>& board, int r, int c) {    
    int live = 0;
    for (int i = r - 1; i <= r + 1; i++) {
      for (int j = c - 1; j <= c + 1; j++) {
        if (0 <= i and i < board.size() and 0 <= j and j < board[0].size() and
            !(i == r and j == c) and (board[i][j] == 1 or board[i][j] == 3))
          live++;
      }
    }
    return live;
  }
};