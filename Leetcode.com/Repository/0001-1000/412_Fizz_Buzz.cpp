// https://leetcode.com/problems/fizz-buzz/

#include <vector>
#include <map>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    map<int, string> map {
      { 3, "Fizz" },
      { 5, "Buzz" }
    };
    
    vector<string> answer (n);
    for (int i = 0; i < n; i++) {
      int val = i + 1;
      string ans;
      for (const auto& [ key, str ] : map) {
        if (val % key == 0)
          ans += str;
      }
      if (ans.length() == 0)
        ans += to_string(val);
      answer[i] = ans;
    }
    return answer;
  }
};