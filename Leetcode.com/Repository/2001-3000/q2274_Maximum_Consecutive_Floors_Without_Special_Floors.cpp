// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    sort(special.begin(), special.end());
    
    int result = 0;
    for (int i = 1; i < special.size(); i++) {
      result = max(result, special[i] - special[i-1] - 1);
    }
    
    return max({ result, special[0] - bottom, top - special.back() });
  }
};