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
        int kadane = 0, maxKadane = INT_MIN;
        for (int r = 0; r < rows; r++) {
          sums[r] += matrix[r][cr];
          kadane = max(kadane + sums[r], sums[r]);
          maxKadane = max(maxKadane, kadane);
        }
        
        if (maxKadane <= k) {
          maxSum = max(maxSum, maxKadane);
          continue;
        }
        
        int curSum = 0;
        prefixSet = { 0 };
        for (const int& sum : sums) {
          curSum += sum;
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
        int curSum = 0;
        prefixSet = { 0 };
        for (const int& sum : sums) {
          curSum += sum;
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