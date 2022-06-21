// https://leetcode.com/problems/largest-number/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    int n = nums.size();
    
    vector<string> strs (n);
    for (int i = 0; i < n; i++) {
      strs[i] = to_string(nums[i]);
    }
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) -> bool {
      return a + b > b + a;
    });
    
    if (strs[0] == "0")
      return "0";
    
    string number;
    for (const string& num : strs) {
      number += num;
    }
    return number;
  }
};