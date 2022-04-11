// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <string>
#include <array>
using namespace std;

class WordDictionary {
private:
  array<WordDictionary*, 26> children;
  bool isEnd;
  
  bool dfs(const string& word, int start, WordDictionary* node) {
    WordDictionary* cur = node;
    
    for (int i = start; i < word.length(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++) {
          if (cur->children[j] && dfs(word, i + 1, cur->children[j]))
            return true;
        }
        return false;
      }
      else if (!cur->children[word[i] - 'a']) {
        return false;
      }
      cur = cur->children[word[i] - 'a'];
    }
    
    return cur->isEnd;
  }
  
public:
  WordDictionary() : isEnd(false) {
    fill(children.begin(), children.end(), nullptr);
  }
  
  void addWord(string word) {
    WordDictionary* cur = this;
    for (const char& ch : word) {
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