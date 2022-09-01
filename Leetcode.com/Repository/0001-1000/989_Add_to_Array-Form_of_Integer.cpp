// https://leetcode.com/problems/add-to-array-form-of-integer/

#include <vector>
using namespace std;

// time: O(max(n, log(k)))
// space: O(1)

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    for (int i = num.size() - 1; i >= 0 and k; i--) {
      num[i] += k;
      k = num[i] / 10;
      num[i] %= 10;
    }
    
    for (; k; k /= 10) {
      num.emplace(num.begin(), k % 10);
    }
    
    return num;
  }
};