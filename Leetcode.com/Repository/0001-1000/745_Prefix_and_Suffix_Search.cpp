// https://leetcode.com/problems/prefix-and-suffix-search/

#include <vector>
#include <string>
#include <array>
using namespace std;

// n = size of words
// w = max len of words
// time: O(n * w^2) for constructor, O(w) for f()
// space: O(n * w^2)

class Trie {
public:
  int weight;
  array<Trie*, 27> children;
  
  Trie() : weight(0) {
    fill(children.begin(), children.end(), nullptr);
  }
};

class WordFilter {
public:
  WordFilter(vector<string>& words) {
    for (int weight = 0; weight < words.size(); weight++) {
      string word = words[weight] + '{';
      for (int i = 0; i < word.length(); i++) {
        Trie* cur = &root;
        for (int j = i; j < word.length() * 2 - 1; j++) {
          int k = word[j % word.length()] - 'a';
          if (!cur->children[k])
            cur->children[k] = new Trie();
          cur = cur->children[k];
          cur->weight = weight;
        }
      }
    }
  }
  
  int f(string pref, string suff) {
    Trie* cur = &root;
    for (char c : suff + '{' + pref) {
      if (!cur->children[c - 'a'])
        return -1;
      cur = cur->children[c - 'a'];
    }
    return cur->weight;
  }
  
private:
  Trie root;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */