// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(2^5) => O(1)

class Solution {
public:
  int findTheLongestSubstring(string& s) {
    unordered_map<int, int> maskIndex {
      { 0, -1 }
    };
    
    int mask = 0, longest = 0;
    for (int i = 0; i < s.length(); i++) {
      if (string("aeiou").find(s[i]) != -1)
        mask ^= 1 << (s[i] - 'a');
      if (maskIndex.count(mask) == 0)
        maskIndex[mask] = i;
      longest = max(longest, i - maskIndex[mask]);
    }
    
    return longest;
  }
};