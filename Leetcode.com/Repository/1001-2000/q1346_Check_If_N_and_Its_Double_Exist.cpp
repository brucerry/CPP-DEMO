// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> set;
    for (const int& num : arr) {
      if (set.count(num * 2) or (num % 2 == 0 and set.count(num / 2)))
        return true;
      set.emplace(num);
    }
    return false;
  }
};