// https://leetcode.com/problems/shifting-letters-ii/

#include <string>
#include <vector>
using namespace std;

// n = len of s
// m = size of shifts
// time: O(m + n)
// space: O(n)

class Solution {
public:
  string shiftingLetters(string& s, vector<vector<int>>& shifts) {
    int n = s.length(), line[50001] {};
    
    for (const auto& shift : shifts) {
      int start = shift[0], end = shift[1], forward = shift[2];
      line[start] += forward ? 1 : -1;
      line[end + 1] += forward ? -1 : 1;
    }
    
    for (int i = 0, shift = 0; i < n; i++) {
      shift = (shift + line[i]) % 26;
      s[i] = (s[i] - 'a' + shift + 26) % 26 + 'a';
    }
    
    return s;
  }
};