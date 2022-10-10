// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string greatestLetter(string& s) {
    int lower = 0, upper = 0;
    char result = 0;
    for (const char& c : s) {
      if (islower(c))
        lower |= 1 << (c - 'a');
      if (isupper(c))
        upper |= 1 << (c - 'A');
      int i = tolower(c) - 'a';
      if ((lower & (1 << i)) and (upper & (1 << i)) and toupper(c) > result)
        result = toupper(c);
    }
    return result == 0 ? "" : string(1, result);
  }
};