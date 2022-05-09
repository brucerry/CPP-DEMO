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

class Solution {  
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie root;
    for (const string& word : words)
      root.addWord(word);
    
    unordered_set<string> used;
    vector<string> result;
    string word;
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        exploreWord(board, r, c, &root, word, result, used);
      }
    }
    
    return result;
  }
  
private:
  struct Trie {
    bool isEnd;
    array<Trie*, 26> children;

    Trie() : isEnd(false) {
      fill(children.begin(), children.end(), nullptr);
    }

    void addWord(const string& word) {
      Trie* cur = this;
      for (const char& c : word) {
        if (!cur->children[c - 'a'])
          cur->children[c - 'a'] = new Trie();
        cur = cur->children[c - 'a'];
      }
      cur->isEnd = true;
    }
  };
  
  void exploreWord(vector<vector<char>>& board, int r, int c, Trie* node, string& word, vector<string>& result, unordered_set<string>& used) {
    if (r < 0 or r >= board.size() or c < 0 or c >= board[0].size() or board[r][c] == '*' or !node->children[board[r][c] - 'a'])
      return;
    
    node = node->children[board[r][c] - 'a'];
    word += board[r][c];
    board[r][c] = '*';
    
    if (node->isEnd and used.count(word) == 0) {
      used.emplace(word);
      result.emplace_back(word);
    }
    
    exploreWord(board, r+1, c, node, word, result, used);
    exploreWord(board, r-1, c, node, word, result, used);
    exploreWord(board, r, c+1, node, word, result, used);
    exploreWord(board, r, c-1, node, word, result, used);
    
    board[r][c] = word.back();
    word.pop_back();
  }
};