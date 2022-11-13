// https://leetcode.com/problems/reverse-words-in-a-string/

#include <string>
#include <sstream>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string reverseWords(string s) {
    vector<string> words;
    stringstream ss (s);
    string word;
    while (ss >> word)
      words.emplace_back(word);
    
    string res;
    for (auto it = words.rbegin(); it != words.rend(); it++) {
      if (it != words.rbegin())
        res += ' ';
      res += *it;
    }
    return res;
  }
};