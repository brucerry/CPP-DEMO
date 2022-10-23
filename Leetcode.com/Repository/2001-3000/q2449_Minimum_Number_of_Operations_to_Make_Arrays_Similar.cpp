// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
#define EVEN 0
#define ODD 1

public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    sort(nums.begin(), nums.end());
    sort(target.begin(), target.end());
    
    vector<int> _nums[2], _target[2];
    for (const int& num : nums) {
      _nums[num % 2].emplace_back(num);
    }
    for (const int& tar : target) {
      _target[tar % 2].emplace_back(tar);
    }

    long result = 0;
    for (int i = 0; i < _nums[EVEN].size(); i++) {
      result += abs(_nums[EVEN][i] - _target[EVEN][i]) / 2;
    }
    for (int i = 0; i < _nums[ODD].size(); i++) {
      result += abs(_nums[ODD][i] - _target[ODD][i]) / 2;
    }
    return result / 2;
  }
};