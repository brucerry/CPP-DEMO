// https://leetcode.com/problems/word-search-ii/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// m = len of words
// n = len of each word
// time: O(r * c * m * n)
// space: O(r * c + m + max len of word)

class Solution {
private:
  struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : children(), isEndOfWord(false) {
      fill(children, children + 26, nullptr);
    }

    void addWord(string& word) {
      TrieNode* cur = this;
      for (char& ch : word) {
        if (cur->children[ch - 'a'] == nullptr) {
          cur->children[ch - 'a'] = new TrieNode();
        }
        cur = cur->children[ch - 'a'];
      }
      cur->isEndOfWord = true;
    }
  };

  void explore(vector<vector<char>>& board, vector<string>& words, int r, int c, TrieNode* node, vector<vector<int>>& used, string str, unordered_set<string> &done, vector<string> &result) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
    if (node->children[board[r][c] - 'a'] == nullptr) return;
    if (used[r][c]) return;

    node = node->children[board[r][c] - 'a'];
    str += board[r][c];

    if (node->isEndOfWord && done.count(str) == 0) {
      done.insert(str);
      result.push_back(str);
    }

    used[r][c] = 1;

    explore(board, words, r+1, c, node, used, str, done, result);
    explore(board, words, r-1, c, node, used, str, done, result);
    explore(board, words, r, c+1, node, used, str, done, result);
    explore(board, words, r, c-1, node, used, str, done, result);

    used[r][c] = 0;
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();

    for (string& word : words) {
      root->addWord(word);
    }

    unordered_set<string> done;
    vector<string> result;
    vector<vector<int>> used (board.size(), vector<int>(board[0].size(), 0));

    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        explore(board, words, r, c, root, used, "", done, result);
      }
    }

    return result;
  }
};