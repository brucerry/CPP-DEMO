// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int maximumGroups(vector<int>& grades) {
    int n = grades.size();
    
    int l = 1, r = n;
    while (l < r) {
      int m = l + ((r - l + 1) / 2);
      int sum = (long)(1 + m) * m / 2;
      if (sum <= n)
        l = m;
      else
        r = m - 1;
    }
    
    return l;
  }
};