// https://leetcode.com/problems/multiply-strings/

#include <vector>
#include <string>
using namespace std;

// time: O(n * m)
// space: O(n + m)

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> ans (num1.length() + num2.length(), 0); // 0..4

    for (int i = num1.size() - 1; i >= 0; i--) { // bottom
      for (int j = num2.size() - 1; j >= 0; j--) { // up
        int digit1 = num1[i] - '0';
        int digit2 = num2[j] - '0';
        int product = digit1 * digit2;
        int added = ans[i + j + 1] + (product % 10);
        ans[i + j + 1] = added % 10;
        int carry = added / 10;
        ans[i + j] += (product / 10) + carry;
      }
    }

    int i = 0;
    while (i < ans.size() && ans[i] == 0) i++;

    string result;
    while (i < ans.size()) {
      result += (ans[i] + '0');
      i++;
    }

    return result;
  }
};