// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int n = s.size();
    for (int l = 0, r = n - 1; l < r; l++, r--) {
      while (l < r and vowels.count(s[l]) == 0)
        l++;
      while (l < r and vowels.count(s[r]) == 0)
        r--;
      if (l < r)
        swap(s[l], s[r]);
    }
    return s;
  }
};