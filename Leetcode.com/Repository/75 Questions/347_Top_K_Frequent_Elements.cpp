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
    unordered_map<int, int> intCount;

    for (int& num : nums) {
      intCount[num]++;
    }

    vector<vector<int>> freqs (nums.size() + 1);
    
    for (auto& [ num, count ] : intCount) {
      freqs[count].push_back(num);
    }

    vector<int> result;
    result.reserve(k);

    for (int i = freqs.size() - 1; i >= 0; i--) {
      if (result.size() == k) break;

      for (int& num : freqs[i]) {
        result.emplace_back(num);
      }
    }

    return result;
  }
};