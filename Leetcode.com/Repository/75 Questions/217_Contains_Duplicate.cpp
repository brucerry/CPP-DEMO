// https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numsSet;

    for (int& num : nums) {
      if (numsSet.count(num)) return true;
      numsSet.insert(num);
    }

    return false;
  }
};