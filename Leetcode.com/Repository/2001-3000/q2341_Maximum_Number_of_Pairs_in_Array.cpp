// https://leetcode.com/problems/maximum-number-of-pairs-in-array/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> numberOfPairs(vector<int>& nums) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : nums)
      numCount[num]++;
    
    int pairs = 0, remain = 0;
    for (const auto& [ _, count ] : numCount) {
      pairs += count / 2;
      remain += count % 2;
    }
    
    return { pairs, remain };
  }
};