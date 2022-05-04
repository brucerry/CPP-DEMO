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
    unordered_map<int, int> numCount;
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    vector<vector<int>> freqCount (nums.size() + 1);
    for (const auto& [ num, count ] : numCount) {
      freqCount[count].emplace_back(num);
    }
    
    vector<int> kMostFreq;
    for (int i = freqCount.size() - 1; i >= 0 and kMostFreq.size() < k; i--) {
      for (const auto& num : freqCount[i]) {
        kMostFreq.emplace_back(num);
      }
    }
    
    return kMostFreq;
  }
};