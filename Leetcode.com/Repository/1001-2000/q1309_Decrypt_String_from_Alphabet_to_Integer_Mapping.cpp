// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string freqAlphabets(string s) {
    int end = 0;
    for (int i = 0; i < s.size(); end++) {
      if ((s[i] == '1' or s[i] == '2') and i + 2 < s.size() and s[i+2] == '#') {
        s[end] = toLetter(s[i+1], s[i]);
        i += 3;
      }
      else {
        s[end] = toLetter(s[i]);
        i++;
      }
    }
    return s.substr(0, end);
  }

private:
  char toLetter(char d, char _10d = '0') {
    return (_10d - '0') * 10 + (d - '0') + 'a' - 1;
  }
};