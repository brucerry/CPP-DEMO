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
    unordered_map<int, int> numCount; // num, count
    for (const int& num : nums)
      numCount[num]++;
    
    vector<int> groupNums;
    for (const auto& [ num, _ ] : numCount)
      groupNums.emplace_back(num);
    sort(groupNums.begin(), groupNums.end());
    
    int n = groupNums.size();
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
      int earn = groupNums[i] * numCount[groupNums[i]];
      
      if (i and groupNums[i-1] + 1 == groupNums[i])
        earn = max(earn + one, two);
      else
        earn += two;
      
      one = two;
      two = earn;
    }
    
    return two;
  }
};