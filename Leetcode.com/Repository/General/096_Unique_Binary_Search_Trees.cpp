// https://leetcode.com/problems/unique-binary-search-trees/

#include <vector>
using namespace std;

// time: O(n ^ 2)
// space: O(n)

class Solution {
// private:
//   int numTrees(int n, int each_n, vector<int>& nums) {
//     int ans = 0;

//     for (int i = 1; i <= each_n; i++) {
//       int countLeft = i - 1;
//       int countRight = each_n - i;
//       ans += nums[countLeft] * nums[countRight];
//       if (i == each_n) nums[i] = ans;
//     }

//     return n == each_n ? ans : numTrees(n, each_n + 1, nums);
//   }

public:
  // int numTrees(int n) {
  //   return numTrees(n, 1, nums);
  // }

  int numTrees(int n) {
    vector<int> nums (n + 1, 0);
    nums[0] = 1;

    for (int each_n = 1; each_n <= n; each_n++) {
      for (int i = 1; i <= each_n; i++) {
        int countLeft = i - 1;
        int countRight = each_n - i;
        nums[each_n] += nums[countLeft] * nums[countRight];
      }
    }

    return nums[n];
  }
};