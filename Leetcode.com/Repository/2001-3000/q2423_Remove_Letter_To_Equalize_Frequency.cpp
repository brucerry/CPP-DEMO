// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool equalFrequency(string& word) {
    int charCount[26] {};
    for (const char& c : word) {
      charCount[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
      if (charCount[i]) {
        charCount[i]--;
        if (isPossible(charCount))
          return true;
        charCount[i]++;
      }
    }
    
    return false;
  }
  
private:
  bool isPossible(int* counts) {
    int num = 0;
    for (int i = 0; i < 26; i++) {
      if (counts[i] and num and counts[i] != num)
        return false;
      if (counts[i])
        num = counts[i];
    }
    return true;
  }
};