// https://leetcode.com/problems/word-search/

#include <vector>
#include <string>
using namespace std;

// time: O(3^(r * c))
// space: O(w)

class Solution {
public:
  bool exist(vector<vector<char>>& board, string& word) {
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        if (searchWord(board, word, r, c, 0))
          return true;
      }
    }
    return false;
  }
  
private:
  bool searchWord(vector<vector<char>>& board, string& word, int r, int c, int i) {
    if (i == word.size())
      return true;
    
    if (r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or board[r][c] != word[i])
      return false;
    
    board[r][c] = '*';
    
    if (searchWord(board, word, r+1, c, i+1) or
        searchWord(board, word, r-1, c, i+1) or
        searchWord(board, word, r, c+1, i+1) or
        searchWord(board, word, r, c-1, i+1))
      return true;
    
    board[r][c] = word[i];
    
    return false;
  }
};