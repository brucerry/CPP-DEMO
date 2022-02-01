/*
  https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <tuple>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int> nums) {
    unordered_map<int, tuple<int, int>> LIScount;
    int lenLIS = 0, res = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
      int maxLen = 1, maxCount = 1;

      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] < nums[j]) {
          auto [ len, count ] = LIScount[j];
          if (len + 1 > maxLen) {
            maxLen = len + 1;
            maxCount = count;
          } else if (len + 1 == maxLen) {
            maxCount += count;
          }
        }
      }

      if (maxLen > lenLIS) {
        lenLIS = maxLen;
        res = maxCount;
      } else if (maxLen == lenLIS) {
        res += maxCount;
      }

      LIScount[i] = { maxLen, maxCount };
    }

    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.findNumberOfLIS({1,3,5,4,7}) << endl;
  cout << sol.findNumberOfLIS({2,2,2,2,2}) << endl;
  cout << sol.findNumberOfLIS({1,2,4,3,5,4,7,2}) << endl;
  cout << sol.findNumberOfLIS({1,2,3,1,2,3,1,2,3}) << endl;
}