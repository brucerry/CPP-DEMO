// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// n = size of words
// w = len of word
// time: O(n * w)
// space: O(n * w)

struct Trie {
  int score;
  Trie* children[26];
  
  Trie() : score(0) {
    fill_n(children, 26, nullptr);
  }
  
  void add(const string& s) {
    Trie* cur = this;
    for (const char& c : s) {
      if (!cur->children[c - 'a'])
        cur->children[c - 'a'] = new Trie();
      cur = cur->children[c - 'a'];
      cur->score++;
    }
  }
  
  int getScore(const string& s) {
    Trie* cur = this;
    int result = 0;
    for (const char& c : s) {
      cur = cur->children[c - 'a'];
      result += cur->score;
    }
    return result;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string>& words) {
    Trie* root = new Trie();
    for (const string& word : words) {
      root->add(word);
    }
    
    vector<int> result;
    for (const string& word : words) {
      result.emplace_back(root->getScore(word));
    }
    
    return result;
  }
};