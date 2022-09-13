// https://leetcode.com/problems/utf-8-validation/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int remained_bytes = 0;
    for (const int& byte : data) {
      if (remained_bytes == 0) {
        if ((byte >> 5) == 0b110)
          remained_bytes = 1;
        else if ((byte >> 4) == 0b1110)
          remained_bytes = 2;
        else if ((byte >> 3) == 0b11110)
          remained_bytes = 3;
        else if (byte >> 7)
          return false;
      }
      else {
        if ((byte >> 6) != 0b10)
          return false;
        remained_bytes--;
      }
    }
    
    return remained_bytes == 0;
  }
};