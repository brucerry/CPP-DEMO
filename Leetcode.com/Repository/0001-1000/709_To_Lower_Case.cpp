// https://leetcode.com/problems/to-lower-case/description/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string toLowerCase(string s) {
    for (char& c : s) {
      if (isupper(c))
        c = tolower(c);
    }
    return s;
  }
};