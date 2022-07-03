// https://leetcode.com/problems/decode-the-message/

#include <string>
#include <unordered_map>
using namespace std;

// k = len of key
// m = len of message
// time: O(k + m)
// space: O(26) => O(1)

class Solution {
public:
  string decodeMessage(string& key, string& message) {
    unordered_map<char, char> charMap {
      { ' ', ' ' }
    };
    
    int count = 0;
    for (const char& c : key) {
      if (charMap.count(c) == 0 and count < 26) {
        charMap[c] = count++;
      }
    }
    
    for (char& c : message) {
      c = c == ' ' ? c : charMap[c] + 'a';
    }
    
    return message;
  }
};