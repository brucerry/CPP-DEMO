// https://leetcode.com/problems/reorganize-string/

#include <string>
#include <array>
#include <queue>
using namespace std;

// time: O(26 * log(26)) -> O(1)
// space: O(26) -> O(1)

class Solution {
public:
  string reorganizeString(string& s) {    
    array<int, 26> charCount { 0 };
    for (const char& c : s)
      charCount[c - 'a']++;
    
    priority_queue<pair<int, char>> ready; // count, char
    for (int i = 0; i < 26; i++) {
      if (charCount[i])
        ready.emplace(charCount[i], i + 'a');
    }
    
    string result;
    pair<int, char> prev { 0, 0 }; // count, char
    while (ready.size() or prev.first) {
      if (ready.size() == 0)
        return "";
      
      auto [ count, ch ] = ready.top();
      ready.pop();
      
      result += ch;
      count--;
      
      if (prev.first) {
        ready.emplace(prev);
        prev = { 0, 0 };
      }
      
      if (count)
        prev = { count, ch };
    }
    
    return result;
  }
};