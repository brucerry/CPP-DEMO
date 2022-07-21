// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  string removeDuplicates(string& s, int k) {
    stack<pair<char, int>> stack; // char, count
    for (const char& c : s) {
      if (stack.size() and stack.top().first == c)
        stack.top().second++;
      else
        stack.emplace(c, 1);
        
      if (stack.top().second == k)
        stack.pop();
    }
    
    string result;
    while (stack.size()) {
      auto [ c, count ] = stack.top();
      stack.pop();
      result += string(count, c);
    }
    
    reverse(result.begin(), result.end());
    return result;
  }
};