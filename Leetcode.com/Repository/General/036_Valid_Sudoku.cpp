// https://leetcode.com/problems/valid-sudoku/

#include <vector>
using namespace std;

// time: O(9 * 9 * 9) => O(1)
// space: O(1)

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.' and !isValid(board, r, c))
          return false;
      }
    }
    
    return true;
  }
  
private:
  bool isValid(vector<vector<char>>& board, int r, int c) {
    char ch = board[r][c];
    board[r][c] = '.'; // skip checking this char again
    
    for (int i = 0; i < 9; i++) {
      if (board[r][i] == ch or board[i][c] == ch or board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
        return false;
    }
    
    return true;
  }
};