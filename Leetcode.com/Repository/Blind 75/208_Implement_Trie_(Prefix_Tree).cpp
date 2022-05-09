// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <array>
using namespace std;

// m = # of words in Trie
// n = len of word
// time: O(1) for constructor, O(n) for insert(), search() and startsWith()
// space: O(26 * m * n) -> O(m * n)

class Trie {
public:
  Trie() : isEnd(false) {
    fill(children.begin(), children.end(), nullptr);
  }
  
  void insert(string word) {
    Trie* cur = this;
    for (const char& c : word) {
      if (!cur->children[c - 'a'])
        cur->children[c - 'a'] = new Trie();
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }
  
  bool search(string word) {
    Trie* result = searchPrefix(word);
    return result and result->isEnd;
  }
  
  bool startsWith(string prefix) {
    return searchPrefix(prefix);
  }
  
private:
  bool isEnd;
  array<Trie*, 26> children;
  
  Trie* searchPrefix(string& prefix) {
    Trie* cur = this;
    for (const char& c : prefix) {
      if (!cur->children[c - 'a'])
        return nullptr;
      cur = cur->children[c - 'a'];
    }
    return cur;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */