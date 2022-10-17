// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool checkIfPangram(string sentence) {
    int mask = 0;
    for (const char& c : sentence) {
      mask |= 1 << (c - 'a');
    }
    return mask == (1 << 26) - 1;
  }
};