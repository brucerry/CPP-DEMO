// https://leetcode.com/problems/count-asterisks/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int countAsterisks(string& s) {
    bool valid = true;
    int count = 0;
    for (const char& c : s) {
      if (c == '|')
        valid = !valid;
      if (valid and c == '*')
        count++;
    }
    return count;
  }
};