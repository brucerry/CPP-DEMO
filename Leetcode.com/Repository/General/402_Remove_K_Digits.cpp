// https://leetcode.com/problems/remove-k-digits/

#include <string>
#include <vector>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  string removeKdigits(string& num, int k) {
    string ans;
    vector<char> result;
    result.reserve(num.length());

    for (int i = 0; i < num.length(); i++) {
      while (k > 0 && result.size() && result.back() > num[i]) {
        k--;
        result.pop_back();
      }
      result.emplace_back(num[i]);
    }

    int i = 0;
    while (i < result.size() && result[i] == '0') i++;

    for (int j = i; j < result.size() - k; j++) {
      ans += result[j];
    }

    return ans.length() == 0 ? "0" : ans;
  }
};