// https://leetcode.com/problems/find-good-days-to-rob-the-bank/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    
    vector<int> nonIncreasing (n), nonDecreasing (n);
    for (int i = 1; i < n; i++) {
      if (security[i-1] >= security[i])
        nonIncreasing[i] = nonIncreasing[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (security[i] <= security[i+1])
        nonDecreasing[i] = nonDecreasing[i+1] + 1;
    }
    
    vector<int> goodDays;
    for (int day = time; day < n - time; day++) {
      if (nonIncreasing[day] >= time and nonDecreasing[day] >= time)
        goodDays.emplace_back(day);
    }
    
    return goodDays;
  }
};