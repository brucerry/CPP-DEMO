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
    
    priority_queue<pair<int, char>> maxHeap; // count, char
    for (int i = 0; i < 26; i++) {
      if (charCount[i])
        maxHeap.emplace(charCount[i], i + 'a');
    }
    
    string result;
    pair<int, char> prev { 0, 0 }; // count, char
    while (maxHeap.size() or prev.first) {
      if (maxHeap.size() == 0)
        return "";
      
      auto [ count, c ] = maxHeap.top();
      maxHeap.pop();
      
      result += c;
      count--;
      
      if (prev.first) {
        maxHeap.emplace(prev);
        prev = { 0, 0 };
      }
      
      if (count)
        prev = { count, c };
    }
    
    return result;
  }
};