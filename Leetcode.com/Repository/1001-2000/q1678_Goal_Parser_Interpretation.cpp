// https://leetcode.com/problems/goal-parser-interpretation/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string interpret(string command) {
    string result;
    for (int i = 0; i < command.size(); ) {
      if (command[i] == 'G')
        result += 'G', i++;
      else if (command[i+1] == ')')
        result += 'o', i += 2;
      else
        result += "al", i += 4;
    }
    return result;
  }
};