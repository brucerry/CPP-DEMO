// https://leetcode.com/problems/valid-sudoku/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
private:
  bool isValid(vector<vector<char>>& board, int r, int c) {
    const char ch = board[r][c];
    board[r][c] = '.'; // skip checking this char

    for (int i = 0; i < 9; i++) {
      if (board[r][i] == ch || board[i][c] == ch || board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
        return false;
    }
    return true;
  }

public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.' && !isValid(board, r, c)) return false;
      }
    }
    return true;
  }
};