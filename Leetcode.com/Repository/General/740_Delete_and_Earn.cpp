// https://leetcode.com/problems/delete-and-earn/

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, int> intCount;
    vector<int> groupNums;

    for (const int& num : nums) {
      intCount[num]++;
    }

    groupNums.reserve(intCount.size());
    
    for (const auto& [ num, _ ] : intCount) {
      groupNums.emplace_back(num);
    }

    sort(groupNums.begin(), groupNums.end());

    int one = 0;
    int two = 0;

    for (int i = 0; i < groupNums.size(); i++) {
      int earn = groupNums[i] * intCount[groupNums[i]];
      int tmp;
      if (i > 0 && groupNums[i - 1] == groupNums[i] - 1) {
        tmp = max(earn + one, two);
      }
      else {
        tmp = earn + two;
      }
      one = two;
      two = tmp;
    }

    return two;
  }
};