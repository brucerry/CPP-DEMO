// https://leetcode.com/problems/word-subsets/

#include <vector>
#include <string>
using namespace std;

// c1 = total # of chars in words1
// c2 = total # of chars in words2
// time: O(c1 + c2)
// space: O(1)

class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int combinedCharCount[26] {}, count[26], i;
    for (const string& word : words2) {
      countChar(word, count);
      for (i = 0; i < 26; i++) {
        combinedCharCount[i] = max(combinedCharCount[i], count[i]);
      }
    }
    
    vector<string> result;
    for (const string& word : words1) {
      countChar(word, count);
      for (i = 0; i < 26; i++) {
        if (count[i] < combinedCharCount[i])
          break;
      }
      if (i == 26)
        result.emplace_back(word);
    }
    
    return result;
  }
  
private:
  void countChar(const string& word, int* count) {
    int tmp[26] {};
    for (const char& c : word) {
      tmp[c - 'a']++;
    }
    memcpy(count, tmp, sizeof(tmp));
  }
};