// https://leetcode.com/problems/array-of-doubled-pairs/

#include <vector>
#include <map>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  bool canReorderDoubled(vector<int>& arr) {
    map<int, int, cmp> numCount;
    for (const int& num : arr) {
      numCount[num]++;
    }
    
    for (const auto& [ num, count ] : numCount) {
      if (count == 0)
        continue;
      if (numCount.count(num * 2) == 0 or count > numCount[num * 2])
        return false;
      numCount[num * 2] -= count;
    }
    
    return true;
  }
  
private:
  struct cmp {
    bool operator()(const int& a, const int& b) const {
      return a < 0 and b < 0 ? a > b : a < b;
    }
  };
};