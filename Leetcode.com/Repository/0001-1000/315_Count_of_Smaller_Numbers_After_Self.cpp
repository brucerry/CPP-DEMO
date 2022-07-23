// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <vector>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts (n);
    vector<Info> info (n), tmp (n);
    
    for (int i = 0; i < n; i++)
      info[i] = Info(nums[i], i);
    
    solve(info, tmp, counts, 0, n);
    return counts;
  }
  
private:
  struct Info {
    int val, index;
    Info() {};
    Info(int val, int index) : val(val), index(index) {}
  };
  
  void solve(vector<Info>& info, vector<Info>& tmp, vector<int>& counts, int l, int r) {
    if (r - l == 1)
      return;
    
    int m = l + ((r - l) >> 1);
    solve(info, tmp, counts, l, m);
    solve(info, tmp, counts, m, r);
    
    int count = 0;
    int leftptr = l, rightptr = m, tmpptr = l;
    while (leftptr < m or rightptr < r) {
      if (leftptr == m) {
        tmp[tmpptr] = info[rightptr++];
      }
      else if (rightptr == r) {
        tmp[tmpptr] = info[leftptr++];
        counts[tmp[tmpptr].index] += count;
      }
      else if (info[leftptr].val <= info[rightptr].val) {
        tmp[tmpptr] = info[leftptr++];
        counts[tmp[tmpptr].index] += count;
      }
      else {
        tmp[tmpptr] = info[rightptr++];
        count++;
      }
      tmpptr++;
    }
    
    for (int i = l; i < r; i++)
      info[i] = tmp[i];
  }
};