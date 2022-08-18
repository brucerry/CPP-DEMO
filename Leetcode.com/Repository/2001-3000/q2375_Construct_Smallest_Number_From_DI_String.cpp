// https://leetcode.com/problems/construct-smallest-number-from-di-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)
class Reversal {
public:
  string smallestNumber(string& pattern) {
    string result;
    for (int i = 0, prev_i = -1; i <= pattern.length(); i++) {
      result += i + '1';
      if (i == pattern.length() or pattern[i] == 'I') {
        reverse(result.begin() + prev_i + 1, result.begin() + i + 1);
        prev_i = i;
      }
    }
    return result;
  }
};

// time: less than O(9!) in worst case with pruning
// space: O(n) for recursive call stack
class DFS {
public:
  string smallestNumber(string& pattern) {
    return to_string(solve(pattern, 0, 0, 0));
  }
  
private:
  int solve(string& pattern, int result, int i, int16_t usedMask) {
    if (i > pattern.length())
      return result;
    
    int num = INT_MAX, prev_d = result % 10;
    for (int cur_d = 1; cur_d <= 9; cur_d++) {
      if (usedMask & (1 << cur_d))
        continue;
      if (i == 0 or
          (pattern[i-1] == 'I' and prev_d < cur_d) or
          (pattern[i-1] == 'D' and prev_d > cur_d)) {
        num = min(num, solve(pattern, result * 10 + cur_d, i + 1, usedMask | (1 << cur_d)));
      }
    }
    
    return num;
  }
};