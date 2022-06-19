// https://leetcode.com/problems/search-suggestions-system/

#include <vector>
#include <string>
#include <algorithm>
#include <array>
using namespace std;

// n = size of products
// m = len of searchWord
// time: O(n * log(n) + m * log(n))
// space: O(log(n)) for sorting
class BinarySearch {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string& searchWord) {
    sort(products.begin(), products.end());
    
    vector<vector<string>> result;
    int l = 0, r = products.size() - 1;
    for (int i = 0; i < searchWord.length(); i++) {
      while (l <= r and (i >= products[l].length() or searchWord[i] != products[l][i]))
        l++;
      while (l <= r and (i >= products[r].length() or searchWord[i] != products[r][i]))
        r--;
      int size = l <= r ? min(3, r - l + 1) : 0;
      result.push_back(vector<string>(products.begin() + l, products.begin() + l + size));
    }
    
    return result;
  }
};

// M = total # of characters in products
// n = # of nodes in Trie
// time: O(M) to build Trie
// space: O(n * 26) => O(n)
struct Trie {
  bool isEnd;
  array<Trie*, 26> children;
  
  Trie() : isEnd(false) {
    fill(children.begin(), children.end(), nullptr);
  }
  
  void insert(const string& word) {
    Trie* cur = this;
    for (const char& c : word) {
      if (!cur->children[c - 'a'])
        cur->children[c - 'a'] = new Trie();
      cur = cur->children[c - 'a'];
    }
    cur->isEnd = true;
  }
  
  vector<string> getWords(string& prefix) {
    Trie* cur = this;
    vector<string> result;
    for (const char& c : prefix) {
      if (!cur->children[c - 'a'])
        return result;
      cur = cur->children[c - 'a'];
    }
    dfsSearch(cur, prefix, result);
    return result;
  }
  
  void dfsSearch(Trie* node, string& word, vector<string>& result) {
    if (result.size() == 3)
      return;
    if (node->isEnd)
      result.push_back(word);
    
    for (char c = 'a'; c <= 'z'; c++) {
      if (node->children[c - 'a']) {
        word += c;
        dfsSearch(node->children[c - 'a'], word, result);
        word.pop_back();
      }
    }
  }
};

class TrieDFS {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string& searchWord) {
    Trie* trie = new Trie();
    for (const string& product : products) {
      trie->insert(product);
    }
    
    vector<vector<string>> solution;
    string prefix;
    for (const char& c : searchWord) {
      prefix += c;
      solution.push_back(trie->getWords(prefix));
    }
    
    return solution;
  }
};