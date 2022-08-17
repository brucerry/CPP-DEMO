// https://leetcode.com/problems/unique-morse-code-words/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// n = sum of len of all words
// time: O(n)
// space: O(n)

class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    string strs[26] {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
      "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
      "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    
    unordered_set<string> codes;
    for (const string& word : words) {
      string code;
      for (const char& c : word) {
        code += strs[c - 'a'];
      }
      codes.insert(code);
    }
    
    return codes.size();
  }
};