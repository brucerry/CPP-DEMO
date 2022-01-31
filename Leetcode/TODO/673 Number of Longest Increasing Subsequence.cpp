/*
  https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
  void findNumberOfLIS(vector<int> nums, int start, int prevNum, int len, priority_queue<int> &pq) {
    if (start == nums.size()) {
      pq.push(len);
      return;
    }
    
    pq.push(len);

    if (len == 0) {
      findNumberOfLIS(nums, start + 1, nums[start], len + 1, pq);
    } else {
      for (int i = start; i < nums.size(); i++) {
        if (prevNum < nums[i]) {
          findNumberOfLIS(nums, i + 1, nums[i], len + 1, pq);
        }
      }
    }
  }

  int findNumberOfLIS(vector<int> nums) {
    priority_queue<int> pq;
    
    for (int i = 0; i < nums.size(); i++) {
      findNumberOfLIS(nums, i, -1, 0, pq);
    }

    int longestLen = pq.top();
    int count = 0;
    while (pq.size()) {
      if (pq.top() == longestLen) count++;
      else return count;
      pq.pop();
    }

    return count;
  }
};

int main() {
  Solution sol;
  //cout << sol.findNumberOfLIS({1,3,5,4,7});
  //cout << sol.findNumberOfLIS({2,2,2,2,2});
  //cout << sol.findNumberOfLIS({1,2,4,3,5,4,7,2});
  cout << sol.findNumberOfLIS({1,2,3,1,2,3,1,2,3});
}