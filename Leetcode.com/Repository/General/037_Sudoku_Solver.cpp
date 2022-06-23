// https://leetcode.com/problems/sudoku-solver/submissions/

#include <vector>
using namespace std;

// n = # of blanks to be filled in with backtracking 9 choices each
// time: O(9^n)
// space: O(9 * 9)

class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    solve(board);
  }
  
private:
  bool solve(vector<vector<char>>& board) {    
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] == '.') {
          for (char num = '1'; num <= '9'; num++) {
            if (isValid(board, r, c, num)) {
              board[r][c] = num;
              if (solve(board))
                return true;
              board[r][c] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  
  bool isValid(vector<vector<char>>& board, int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
      if ((num == board[i][c]) or
          (num == board[r][i]) or
          (num == board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3])) {
        return false;
      }
    }
    return true;
  }
};