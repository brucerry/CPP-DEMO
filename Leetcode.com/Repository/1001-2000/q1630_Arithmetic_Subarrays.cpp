// https://leetcode.com/problems/arithmetic-subarrays/

#include <vector>
#include <algorithm>
using namespace std;

// n = size of nums
// m = size of l and r
// time: O(m * n * log(n))
// space: O(n)

class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int n = nums.size(), m = l.size();
    vector<int> tmp;
    vector<bool> answer (m);
    
    for (int i = 0, j; i < m; i++) {
      tmp = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
      sort(tmp.begin(), tmp.end());
      for (j = 1; j < tmp.size(); j++) {
        if (tmp[j] - tmp[j-1] != tmp[1] - tmp[0])
          break;
      }
      answer[i] = j == tmp.size();
    }
    
    return answer;
  }
};