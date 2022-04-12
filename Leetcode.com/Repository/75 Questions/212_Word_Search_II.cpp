// https://leetcode.com/problems/word-search-ii/

#include <vector>
#include <string>
#include <unordered_set>
#include <array>
using namespace std;

// m = len of words
// n = len of each word
// time: O(r * c * m * n)
// space: O(r * c + m + max len of word)

class Solution {
private:
  struct Trie {
    bool isEnd;
    array<Trie*, 26> children;

    Trie() : isEnd(false) {
      fill(children.begin(), children.end(), nullptr);
    }

    void addWord(const string& word) {
      Trie* cur = this;
      for (const char& ch : word) {
        if (!cur->children[ch - 'a']) {
          cur->children[ch - 'a'] = new Trie();
        }
        cur = cur->children[ch - 'a'];
      }
      cur->isEnd = true;
    }
  };
  
  void explore(vector<vector<char>>& board, int r, int c, Trie* node, string& word, vector<string>& result, unordered_set<string>& used) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '*' || !node->children[board[r][c] - 'a'])
      return;
    
    node = node->children[board[r][c] - 'a'];
    word += board[r][c];
    
    if (node->isEnd && used.count(word) == 0) {
      used.emplace(word);
      result.emplace_back(word);
    }
    
    board[r][c] = '*';
    
    explore(board, r+1, c, node, word, result, used);
    explore(board, r-1, c, node, word, result, used);
    explore(board, r, c+1, node, word, result, used);
    explore(board, r, c-1, node, word, result, used);
    
    board[r][c] = word.back();
    
    word.pop_back();
  }
  
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie root;
    
    for (const string& word : words) {
      root.addWord(word);
    }
    
    vector<string> result;
    string word;
    unordered_set<string> used;
    
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        explore(board, r, c, &root, word, result, used);
      }
    }
    
    return result;
  }
};