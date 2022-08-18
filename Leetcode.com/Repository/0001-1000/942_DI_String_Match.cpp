// https://leetcode.com/problems/di-string-match/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)
class TwoPointers {
public:
  vector<int> diStringMatch(string& s) {
    int n = s.length();
    vector<int> result (n + 1);
    
    for (int i = 0, small = 0, large = n; i <= n; i++) {
      result[i] = s[i] == 'D' ? large-- : small++;
    }
    
    return result;
  }
};

// time: O(n)
// space: O(1)
class Reversal {
public:
  vector<int> diStringMatch(string& s) {
    int n = s.length();
    vector<int> result (n + 1);
    
    for (int i = 0, prev_I = -1; i <= n; i++) {
      result[i] = i;
      if (i == n or s[i] == 'I') {
        reverse(result.begin() + prev_I + 1, result.begin() + i + 1);
        prev_I = i;
      }
    }
    
    return result;
  }
};