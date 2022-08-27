// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#include <vector>
#include <set>
using namespace std;

// time: O(c^2 * r * log(r))
// space: O(r)
class KadaneDP {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> sums (rows);
    set<int> prefixSet;
    
    int maxSum = INT_MIN;
    for (int cl = 0; cl < cols; cl++) {
      fill(sums.begin(), sums.end(), 0);
      for (int cr = cl; cr < cols; cr++) {
        int kadane = INT_MIN;
        for (int r = 0, curSum = 0; r < rows; r++) {
          sums[r] += matrix[r][cr];
          curSum = max(curSum + sums[r], sums[r]);
          kadane = max(kadane, curSum);
        }
        
        if (kadane <= k) {
          maxSum = max(maxSum, kadane);
          continue;
        }
        
        prefixSet = { 0 };
        for (int i = 0, curSum = 0; i < rows; i++) {
          curSum += sums[i];
          auto it = prefixSet.lower_bound(curSum - k);
          if (it != prefixSet.end())
            maxSum = max(maxSum, curSum - *it);
          prefixSet.insert(curSum);
        }
      }
    }
    
    return maxSum;
  }
};

// time: O(c^2 * r * log(r))
// space: O(r)
class DP {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> sums (rows);
    set<int> prefixSet;
    
    int maxSum = INT_MIN;
    for (int cl = 0; cl < cols; cl++) {
      fill(sums.begin(), sums.end(), 0);
      for (int cr = cl; cr < cols; cr++) {
        for (int r = 0; r < rows; r++) {
          sums[r] += matrix[r][cr];
        }
        prefixSet = { 0 };
        for (int i = 0, curSum = 0; i < rows; i++) {
          curSum += sums[i];
          auto it = prefixSet.lower_bound(curSum - k);
          if (it != prefixSet.end())
            maxSum = max(maxSum, curSum - *it);
          prefixSet.insert(curSum);
        }
      }
    }
    
    return maxSum;
  }
};