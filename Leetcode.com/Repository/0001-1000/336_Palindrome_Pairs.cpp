// https://leetcode.com/problems/palindrome-pairs/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// n = size of words
// w = len of word
// time: O(n * w^2)
// space: O(n * w)

struct Trie {
  Trie* children[26];
  vector<int> indices;
  int index;
  
  Trie() : index(-1) {
    fill_n(children, 26, nullptr);
  }

  void add(const string& word, int index) {
    Trie* cur = this;
    for (int j = word.length() - 1; j >= 0; j--) {
      if (isPalindrome(word, 0, j))
        cur->indices.emplace_back(index);
      
      if (!cur->children[word[j] - 'a'])
        cur->children[word[j] - 'a'] = new Trie();
      cur = cur->children[word[j] - 'a'];
    }
    
    cur->indices.emplace_back(index);
    cur->index = index;
  }
  
  void search(const string& word, int index, vector<vector<int>>& result) {
    Trie* cur = this;
    for (int j = 0; j < word.length(); j++) {
      if (cur->index >= 0 and cur->index != index and isPalindrome(word, j, word.length() - 1))
        result.push_back({ index, cur->index });
      cur = cur->children[word[j] - 'a'];
      if (!cur)
        return;
    }
    
    for (const int& i : cur->indices) {
      if (i != index)
        result.push_back({ index, i });
    }
  }
  
  bool isPalindrome(const string& s, int l, int r) {
    for (; l < r; l++, r--) {
      if (s[l] != s[r])
        return false;
    }
    return true;
  }
};

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    Trie* root = new Trie();
    for (int i = 0; i < words.size(); i++) {
      root->add(words[i], i);
    }
    
    vector<vector<int>> result;
    for (int i = 0; i < words.size(); i++) {
      root->search(words[i], i, result);
    }
    
    return result;
  }
};