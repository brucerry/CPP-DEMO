// https://leetcode.com/problems/top-k-frequent-elements/

#include <vector>
#include <unordered_map>
using namespace std;

// seem like Bucket Sort
// use frequency as array index

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    int n = nums.size();
    vector<vector<int>> countGroups (n + 1);
    for (const auto& [ num, count ] : numCount) {
      countGroups[count].emplace_back(num);
    }
    
    vector<int> result;
    for (int count = n; count >= 0 and result.size() < k; count--) {
      for (const int& num : countGroups[count]) {
        result.emplace_back(num);
      }
    }
    
    return result;
  }
};