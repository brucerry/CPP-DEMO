// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    unordered_map<long, int> diffCount[1000];
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        long diff = (long)nums[i] - nums[j];
        int count = diffCount[j].count(diff) ? diffCount[j][diff] : 0;
        diffCount[i][diff] += count + 1;
        result += count;
      }
    }
    return result;
  }
};