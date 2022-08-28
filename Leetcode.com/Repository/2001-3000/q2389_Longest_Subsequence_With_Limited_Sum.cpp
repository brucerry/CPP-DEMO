// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

#include <vector>
#include <algorithm>
using namespace std;

// n = size of nums
// q = size of queries
// time: O(n * log(n) + q * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i-1];
    }
    
    int q = queries.size();
    vector<int> answer (q);
    for (int i = 0; i < q; i++) {
      answer[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
    }
    
    return answer;
  }
};