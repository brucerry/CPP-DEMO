// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

#include <string>
#include <vector>
using namespace std;

// n = size of dictionary
// m = len of each word
// time: O(n * m)
// space: O(1)

class Solution {
public:
  string findLongestWord(string& s, vector<string>& dictionary) {    
    string result;
    for (const string& word : dictionary) {
      if (isSubsequence(s, word) and (word.length() > result.length() or (word.length() == result.length() and word < result)))
        result = word;
    }
    return result;
  }
  
private:
  bool isSubsequence(const string& s, const string& word) {
    int m = s.length(), n = word.length();
    int i = 0, j = 0;
    while (i < m and j < n) {
      if (s[i] == word[j])
        j++;
      i++;
    }
    return j == n;
  }
};