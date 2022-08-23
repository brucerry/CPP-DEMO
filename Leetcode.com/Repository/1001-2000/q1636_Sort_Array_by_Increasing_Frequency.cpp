// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    int counts[201] {};
    for (const int& num : nums)
      counts[num+100]++;
    
    sort(nums.begin(), nums.end(), [&](const int& a, const int& b) -> bool {
      return counts[a+100] == counts[b+100] ? a > b : counts[a+100] < counts[b+100];
    });
    
    return nums;
  }
};