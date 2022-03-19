// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
using namespace std;

class Trie {
private:
  Trie* children[26];
  bool isEnd;

  Trie* searchPrefix(string& word) {
    Trie* cur = this;
    for (char& ch : word) {
      if (!cur->children[ch - 'a']) return nullptr;
      cur = cur->children[ch - 'a'];
    }
    return cur;
  }

public:
  Trie() : children(), isEnd(false) {
    fill(children, children + 26, nullptr);
  }
    
  void insert(string word) {
    Trie* cur = this;
    for (char& ch : word) {
      if (!cur->children[ch - 'a']) {
        cur->children[ch - 'a'] = new Trie();
      }
      cur = cur->children[ch - 'a'];
    }
    cur->isEnd = true;
  }
    
  bool search(string word) {
    Trie* node = searchPrefix(word);
    return node && node->isEnd;
  }
    
  bool startsWith(string prefix) {
    Trie* node = searchPrefix(prefix);
    return node;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */