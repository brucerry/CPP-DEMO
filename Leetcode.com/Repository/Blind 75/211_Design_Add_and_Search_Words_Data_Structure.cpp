// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <string>
#include <array>
using namespace std;

class WordDictionary {
public:
  WordDictionary() : isEnd(false) {
    fill(children.begin(), children.end(), nullptr);
  }
  
  void addWord(string word) {
    WordDictionary* cur = this;
    for (const char& c : word) {
      if (!cur->children[c - 'a'])
        cur->children[c - 'a'] = new WordDictionary();
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }
  
  bool search(string word) {
    return dfsSearch(word, this, 0);
  }
  
private:
  bool dfsSearch(string& word, WordDictionary* node, int start) {
    WordDictionary* cur = node;
    
    for (int i = start; i < word.length(); i++) {
      if (word[i] == '.') {
        for (int j = 0; j < 26; j++) {
          if (cur->children[j] and dfsSearch(word, cur->children[j], i + 1))
            return true;
        }
        return false;
      }
      else if (!cur->children[word[i] - 'a'])
        return false;
      
      cur = cur->children[word[i] - 'a'];
    }
    
    return cur->isEnd;
  }

private:
  bool isEnd;
  array<WordDictionary*, 26> children;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */