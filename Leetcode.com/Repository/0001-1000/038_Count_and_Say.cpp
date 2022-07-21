// https://leetcode.com/problems/count-and-say/

#include <string>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string str = "1";
    
    for (int i = 2; i <= n; i++) {
      int count = 1;
      char say = str[0];
      string tmp;
      
      for (int j = 1; j < str.length(); j++) {
        if (say == str[j]) {
          count++;
        }
        else {
          tmp += count + '0';
          tmp += say;
          count = 1;
          say = str[j];
        }
      }
      
      tmp += count + '0';
      tmp += say;
      
      str = tmp;
    }
    
    return str;
  }
};