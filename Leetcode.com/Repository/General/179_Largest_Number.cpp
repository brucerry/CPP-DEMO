// https://leetcode.com/problems/largest-number/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> strs (nums.size());

    for (int i = 0; i < nums.size(); i++) {
      strs[i] = to_string(nums[i]);
    }

    sort(strs.begin(), strs.end(), [](const string& a, const string& b) -> bool {
      return a + b > b + a;
    });

    string ans = accumulate(strs.begin(), strs.end(), string(""));

    return ans[0] == '0' ? "0" : ans;
  }
};