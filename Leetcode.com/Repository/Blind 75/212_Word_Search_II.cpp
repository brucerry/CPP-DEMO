// https://leetcode.com/problems/word-search-ii/

#include <vector>
#include <string>
#include <unordered_set>
#include <array>
using namespace std;

// m = # of words
// n = len of each word
// time: O(r * c * 3^n)
// space: O(26 * m * n) -> O(m * n)

struct Trie {
  Trie* children[26] = {};
  bool isEnd = false;

  void add(const string& word) {
    Trie* cur = this;
    for (const char& c : word) {
      if (!cur->children[c - 'a'])
        cur->children[c - 'a'] = new Trie();
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie root;
    for (const string& word : words) {
      root.add(word);
    }

    unordered_set<string> result;
    string str;
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        dfs(board, &root, r, c, str, result);
      }
    }

    return vector<string>(result.begin(), result.end());
  }

  void dfs(vector<vector<char>>& board, Trie* root, int r, int c, string& str, unordered_set<string>& result) {
    if (r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or board[r][c] == '*' or !root->children[board[r][c] - 'a'])
      return;

    root = root->children[board[r][c] - 'a'];
    str += board[r][c];
    board[r][c] = '*';

    if (root->isEnd)
      result.insert(str);

    dfs(board, root, r+1, c, str, result);
    dfs(board, root, r-1, c, str, result);
    dfs(board, root, r, c+1, str, result);
    dfs(board, root, r, c-1, str, result);

    board[r][c] = str.back();
    str.pop_back();
  }
};