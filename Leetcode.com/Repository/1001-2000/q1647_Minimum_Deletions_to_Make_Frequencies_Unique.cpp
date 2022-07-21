// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <array>
#include <string>
#include <algorithm>
using namespace std;

// time: O(n + 26 * log(26)) => O(n)
// space: O(26) => O(1)

class Solution {
public:
  int minDeletions(string& s) {
    array<int, 26> charCount { 0 };
    for (const char& c : s) {
      charCount[c - 'a']++;
    }
    
    sort(charCount.rbegin(), charCount.rend());
    
    int deleteCount = 0, allowedMax = s.length();
    for (int i = 0; i < 26 and charCount[i]; i++) {
      if (charCount[i] > allowedMax) {
        deleteCount += charCount[i] - allowedMax;
        charCount[i] = allowedMax;
      }
      allowedMax = max(0, charCount[i] - 1);
    }
    
    return deleteCount;
  }
};