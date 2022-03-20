// https://leetcode.com/problems/encode-and-decode-strings/description/

#include <vector>
#include <string>
using namespace std;

// time: O(n) for encode, O(s) for decode
// space: O(1)

class Solution {
public:
  string encode(vector<string>& strs) {
    string output;
    for (string& str : strs) {
      output += to_string(str.length()) + '#' + str;
    }
    return output;
  }

  vector<string> decode(string& s) {
    vector<string> output;

    int i = 0;

    while (i < s.length()) {
      string tmp;
      while (isdigit(s[i])) {
        tmp += s[i];
        i++;
      }
      int len = stoi(tmp);
      i++;
      output.push_back(s.substr(i, len));
      i += len;
    }

    return output;
  }
};