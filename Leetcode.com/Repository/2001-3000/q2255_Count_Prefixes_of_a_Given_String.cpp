// https://leetcode.com/problems/count-prefixes-of-a-given-string/

#include <vector>
#include <string>
using namespace std;

// w = size of words
// s = len of s
// time: O(w * s)
// space: O(1)

class Solution {
public:
  int countPrefixes(vector<string>& words, string& s) {
    int result = 0;
    for (const string& word : words) {
      if (s.find(word, 0) == 0)
        result++;
    }
    return result;
  }
};