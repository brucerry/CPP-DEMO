// https://leetcode.com/problems/query-kth-smallest-trimmed-number/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// n = size of nums
// q = size of queries
// time: O(q * n)
// space: O(n)
class NthElement {
public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), len = nums[0].length(), q = queries.size();
    
    vector<pair<string, int>> pairs (n); // num, index
    for (int i = 0; i < n; i++) {
      pairs[i] = { nums[i], i };
    }
    
    vector<int> result (q);
    for (int i = 0; i < q; i++) {
      int kth = queries[i][0];
      int trim = queries[i][1];
      nth_element(pairs.begin(), pairs.begin() + kth - 1, pairs.end(), [&](const pair<string, int>& a, const pair<string, int>& b) -> bool {
        int result = a.first.compare(len - trim, trim, b.first, len - trim, trim);
        return result == 0 ? a.second < b.second : result < 0;
      });
      result[i] = pairs[kth-1].second;
    }
    
    return result;
  }
};

// n = size of nums
// q = size of queries
// time: O(q * n * log(n))
// space: O(n)
class Sorting {
public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), len = nums[0].length(), q = queries.size();
    
    vector<pair<string, int>> pairs (n); // num, index
    for (int i = 0; i < n; i++) {
      pairs[i] = { nums[i], i };
    }
    
    vector<int> result (q);
    for (int i = 0; i < q; i++) {
      int kth = queries[i][0];
      int trim = queries[i][1];
      sort(pairs.begin(), pairs.end(), [&](const pair<string, int>& a, const pair<string, int>& b) -> bool {
        int result = a.first.compare(len - trim, trim, b.first, len - trim, trim);
        return result == 0 ? a.second < b.second : result < 0;
      });
      result[i] = pairs[kth-1].second;
    }
    
    return result;
  }
};