// https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    
    for (const int& num : nums) {
      if (set.count(num)) return true;
      set.emplace(num);
    }
    
    return false;
  }
};