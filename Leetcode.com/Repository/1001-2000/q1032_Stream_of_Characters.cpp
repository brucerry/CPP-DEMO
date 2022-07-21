// https://leetcode.com/problems/stream-of-characters/

#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

// n = size of words
// s = len of each word
// time: O(n * s) for constructor, O(max(s)) for query
// space: O(n * s)

class StreamChecker {
public:
  StreamChecker(vector<string>& words) {
    for (const string& word : words) {
      root.add(word);
    }
  }
  
  bool query(char letter) {
    stream += letter;
    Trie* cur = &root;
    for (auto c = stream.rbegin(); c != stream.rend() and cur; c++) {
      cur = cur->children[*c - 'a'];
      if (cur and cur->isEnd)
        return true;
    }
    return false;
  }
  
private:
  struct Trie {
    bool isEnd;
    array<Trie*, 26> children;
    
    Trie() : isEnd(false) {
      fill(children.begin(), children.end(), nullptr);
    }
    
    void add(const string& word) {
      Trie* cur = this;
      for (auto c = word.rbegin(); c != word.rend(); c++) {
        if (!cur->children[*c - 'a'])
          cur->children[*c - 'a'] = new Trie();
        cur = cur->children[*c - 'a'];
      }
      cur->isEnd = true;
    }
  };
  
  Trie root;
  string stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */