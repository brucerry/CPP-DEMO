// https://leetcode.com/problems/number-of-valid-clock-times/

#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  int countTime(string time) {
    int result = 1;
    
    if (time[0] == '?' and time[1] == '?')
      result *= 24;
    else if (time[0] == '?')
      result *= time[1] - '0' < 4 ? 3 : 2;
    else if (time[1] == '?')
      result *= time[0] - '0' < 2 ? 10 : 4; 
    
    if (time[3] == '?' and time[4] == '?')
      result *= 60;
    else if (time[3] == '?')
      result *= 6;
    else if (time[4] == '?')
      result *= 10;
    
    return result;
  }
};