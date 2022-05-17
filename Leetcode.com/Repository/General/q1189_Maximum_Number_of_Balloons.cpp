// https://leetcode.com/problems/maximum-number-of-balloons/

#include <string>
#include <array>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxNumberOfBalloons(string& text) {
    array<int, 26> charCount { 0 };
    for (const char& c : text)
      charCount[c - 'a']++;
    
    return min({ charCount['b' - 'a'], charCount['a' - 'a'], charCount['l' - 'a'] >> 1, charCount['o' - 'a'] >> 1, charCount['n' - 'a'] });
  }
};