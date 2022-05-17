// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <vector>
#include <string>
#include <array>
using namespace std;

// n = size of words
// m = len of each word
// time: O(n * m)
// space: O(26) -> O(1)

class Solution {
public:
  bool isAlienSorted(vector<string>& words, string& order) {
    array<char, 26> orderIndex;
    for (int i = 0; i < order.length(); i++)
      orderIndex[order[i] - 'a'] = i;
    
    for (int i = 1; i < words.size(); i++) {
      string& w1 = words[i-1];
      string& w2 = words[i];
      
      for (int j = 0; j < w1.length(); j++) {
        if (j == w2.length())
          return false;
        
        if (w1[j] != w2[j]) {
          if (orderIndex[w1[j] - 'a'] > orderIndex[w2[j] - 'a'])
            return false;
          break;
        }
      }
    }
    
    return true;
  }
};