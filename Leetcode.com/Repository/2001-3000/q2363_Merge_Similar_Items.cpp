// https://leetcode.com/problems/merge-similar-items/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    int weights[1001] {};
    
    for (const auto& item : items1) {
      int value = item[0];
      int weight = item[1];
      weights[value] += weight;
    }
    
    for (const auto& item : items2) {
      int value = item[0];
      int weight = item[1];
      weights[value] += weight;
    }
    
    vector<vector<int>> result;
    for (int value = 1; value <= 1000; value++) {
      if (weights[value])
        result.push_back({ value, weights[value] });
    }
    
    return result;
  }
};