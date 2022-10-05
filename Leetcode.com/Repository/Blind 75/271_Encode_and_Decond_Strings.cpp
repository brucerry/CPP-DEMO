// https://leetcode.com/problems/encode-and-decode-strings/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
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

  vector<string> decode(string &str) {
    vector<string> output;

    int i = 0;
    while (i < str.length()) {
      string len;
      while (str[i] != '#')
        len += str[i++];
      int n = stoi(len);

      i++;
      output.emplace_back(str.substr(i, n));
      i += n;
    }

    return output;
  }
};