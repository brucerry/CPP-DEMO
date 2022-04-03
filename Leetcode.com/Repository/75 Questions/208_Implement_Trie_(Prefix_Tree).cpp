// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <array>
using namespace std;

class Trie {
private:
  array<Trie*, 26> children;
  bool isEnd;
  
  Trie* searchPrefix(const string& word) {
    Trie* cur = this;
    for (const char& ch : word) {
      if (!cur->children[ch - 'a']) return nullptr;
      cur = cur->children[ch - 'a'];
    }
    return cur;
  }
  
public:
  Trie() : isEnd(false) {
    fill(children.begin(), children.end(), nullptr);
  }
  
  void insert(string word) {
    Trie* cur = this;
    for (const char& ch : word) {
      if (!cur->children[ch - 'a']) {
        cur->children[ch - 'a'] = new Trie();
      }
      cur = cur->children[ch - 'a'];
    }
    cur->isEnd = true;
  }
  
  bool search(string word) {
    Trie* result = searchPrefix(word);
    return result && result->isEnd;
  }
  
  bool startsWith(string prefix) {
    Trie* result = searchPrefix(prefix);
    return result;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */