// https://leetcode.com/problems/short-encoding-of-words/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// n = size of words
// m = len of each word
// time: O(n * m^2)
// space: O(n)
class StorePrefixes {
public:
  int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> wordSet (words.begin(), words.end());
    for (const string& word : wordSet) {
      for (int i = 1; i < word.length(); i++) {
        wordSet.erase(word.substr(i));
      }
    }
    
    int len = 0;
    for (const string& word : wordSet) {
      len += word.length() + 1;
    }
    return len;
  }
};

// n = size of words
// m = len of each word
// time: O(n * m)
// space: O(n)
struct Trie {
  bool isInserted = false;
  unordered_map<char, Trie*> children;
  
  Trie* insert(const string& word) {
    Trie* cur = this;
    for (int i = word.length() - 1; i >= 0; i--) {
      char c = word[i];
      if (!cur->children[c]) {
        cur->children[c] = new Trie();
      }
      cur = cur->children[c];
    }
    
    if (cur->isInserted) // check if the word has already been inserted to Trie
      return nullptr;
    
    cur->isInserted = true;
    return cur;
  }
};

class Solution {
public:
  int minimumLengthEncoding(vector<string>& words) {
    int n = words.size();
    vector<pair<Trie*, int>> nodeDepth (n); // node, depth
    
    Trie* trie = new Trie();
    for (int i = 0; i < n; i++) {
      Trie* node = trie->insert(words[i]);
      nodeDepth[i] = { node, words[i].length() + 1 };
    }
    
    int len = 0;
    for (int i = 0; i < n; i++) {
      auto& [ node, depth ] = nodeDepth[i];
      if (node and node->children.size() == 0)
        len += depth;
    }
    return len;
  }
};