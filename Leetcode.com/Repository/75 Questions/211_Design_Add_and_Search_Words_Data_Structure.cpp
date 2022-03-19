// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <string>
#include <unordered_map>
using namespace std;

class WordDictionary {
private:
  WordDictionary* children[26];
  bool isEnd;

  bool dfs(string& word, int start, WordDictionary* n) {
    WordDictionary* cur = n;
    for (int i = start; i < word.size(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++) {
          if (cur->children[j] && dfs(word, i + 1, cur->children[j])) return true;
        }
        return false;
      }
      else {
        if (!cur->children[word[i] - 'a']) return false;
        cur = cur->children[word[i] - 'a'];
      }
    }
    return cur->isEnd;
  }

public:
  WordDictionary() : children(), isEnd(false) {
    fill(children, children + 26, nullptr);
  }
  
  void addWord(string word) {
    WordDictionary* cur = this;
    for (char& ch : word) {
      if (!cur->children[ch - 'a']) {
        cur->children[ch - 'a'] = new WordDictionary();
      }
      cur = cur->children[ch - 'a'];
    }
    cur->isEnd = true;
  }
  
  bool search(string word) {
    return dfs(word, 0, this);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */