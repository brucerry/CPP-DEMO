/*
  https://leetcode.com/problems/sudoku-solver/
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

  unordered_set<char> DIGITS = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  // helper functions
  vector<vector<char>> getRows(vector<vector<char>> board) {
    return board;
  }

  vector<vector<char>> getCols(vector<vector<char>> board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<char>> colsCollections (row, vector<char>(col));

    for (int c = 0; c < col; c++) {
      vector<char> v;
      for (int r = 0; r < row; r++) {
        v.push_back(board[r][c]);
      }
      colsCollections.push_back(v);
    }

    return colsCollections;
  }

  /*
    subGridId:
    0 1 2
    3 4 5
    6 7 8
  */
  vector<char> getSubGrid(int subGridId, vector<vector<char>> board) {
    vector<char> v;
    int row = 3 * (subGridId / 3);
    int col = 3 * (subGridId % 3);
    for (int r = row; r < row + 3; r++) {
      for (int c = col; c < col + 3; c++) {
        v.push_back(board[r][c]);
      }
    }
    return v;
  }

  vector<vector<char>> getGrids(vector<vector<char>> board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<char>> gridsCollections (row, vector<char>(col));

    for (int subGridId = 0; subGridId < 9; subGridId++) {
      vector<char> v = getSubGrid(subGridId, board);
      gridsCollections.push_back(v);
    }

    return gridsCollections;
  }

  void getKthRowInSet(unordered_set<char> &usedDigits, vector<vector<char>> board, int row) {
    copy(board[row].begin(), board[row].end(), inserter(usedDigits, usedDigits.end()));
  }

  void getKthColInSet(unordered_set<char> &usedDigits, vector<vector<char>> board, int col) {
    for (auto row : board) {
      usedDigits.insert(row[col]);
    }
  }

  void getGridInSet(unordered_set<char> &usedDigits, vector<vector<char>> board, int row, int col) {
    int subGridId = 0;
    if (0 <= row && row <= 2) {
      if (0 <= col && col <= 2) {
        subGridId = 0;
      }
      else if (3 <= col && col <= 5) {
        subGridId = 1;
      }
      else {
        subGridId = 2;
      }
    }
    else if (3 <= row && row <= 5) {
      if (0 <= col && col <= 2) {
        subGridId = 3;
      }
      else if (3 <= col && col <= 5) {
        subGridId = 4;
      }
      else {
        subGridId = 5;
      }
    }
    else {
      if (0 <= col && col <= 2) {
        subGridId = 6;
      }
      else if (3 <= col && col <= 5) {
        subGridId = 7;
      }
      else {
        subGridId = 8;
      }
    }

    vector<char> v = getSubGrid(subGridId, board);
    copy(v.begin(), v.end(), inserter(usedDigits, usedDigits.end()));
  }
  // helper functions

  void solveSudoku(vector<vector<char>>& board) {
    if (!search(board))
      cout << "No solutions" << endl;
  }

  bool isValidState(vector<vector<char>> board) {
    for (auto row : getRows(board)) {
      if (DIGITS != unordered_set<char> (row.begin(), row.end())) {
        return false;
      }
    }

    for (auto col : getCols(board)) {
      if (DIGITS != unordered_set<char> (col.begin(), col.end())) {
        return false;
      }
    }
    
    for (auto grid : getGrids(board)) {
      if (DIGITS != unordered_set<char> (grid.begin(), grid.end())) {
        return false;
      }
    }

    return true;
  }

  vector<char> getCandidates(vector<vector<char>> board, int row, int col) {
    unordered_set<char> usedDigits;
    getKthRowInSet(usedDigits, board, row);
    getKthColInSet(usedDigits, board, col);
    getGridInSet(usedDigits, board, row, col);
    usedDigits.erase('.');
    unordered_set<char> candidates;
    for (auto digit : DIGITS) {
      if (!usedDigits.count(digit)) {
        candidates.insert(digit);
      }
    }
    //set_difference(DIGITS.begin(), DIGITS.end(), usedDigits.begin(), usedDigits.end(), inserter(candidates, candidates.end()));
    return vector<char> (candidates.begin(), candidates.end());
  }

  bool search(vector<vector<char>>& board) {
    if (isValidState(board)) return true;

    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (board[r][c] == '.'){
          for (auto candidate : getCandidates(board, r, c)) {
            board[r][c] = candidate;
            if (search(board)) return true; // valid after try a candidate
            board[r][c] = '.'; // backtracking
          }
          return false; // exhausted all candidates but still invalid
        }
      }
    }

    return true; // no empty spot '.'
  }
};

int main()
{
  vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  Solution sol;
  sol.solveSudoku(board);

  for (auto rows : board)
  {
    for (auto ch : rows)
    {
      cout << ch;
    }
    cout << endl;
  }
}