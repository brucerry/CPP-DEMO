// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  string removeDuplicates(string& s, int k) {
    stack<pair<char, int>> stack; // letter, contiguous equal count
    for (const char& c : s) {      
      if (stack.size() == 0 or stack.top().first != c)
        stack.emplace(c, 1);
      else
        stack.top().second++;
      
      if (stack.top().second == k)
        stack.pop();
    }
    
    string result;
    while (stack.size()) {
      auto [ letter, count ] = stack.top();
      stack.pop();
      result += string(count, letter);
    }
    
    reverse(result.begin(), result.end());
    
    return result;
  }
};