// https://leetcode.com/problems/binary-trees-with-factors/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    unordered_map<int, int> dp; // rootVal, count
    
    int trees = 0;
    for (int i = 0; i < arr.size(); i++) {
      dp[arr[i]] = 1;
      for (int j = 0; j < i; j++) {
        if (arr[i] % arr[j] == 0)
          dp[arr[i]] = (dp[arr[i]] + (long)dp[arr[j]] * dp[arr[i] / arr[j]]) % 1000000007;
      }
      trees = (trees + dp[arr[i]]) % 1000000007;
    }
    
    return trees;
  }
};