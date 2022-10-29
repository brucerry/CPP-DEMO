// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<int> indices (n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
      return growTime[i] > growTime[j];
    });
    int result = 0, curPlantTime = 0;
    for (const int& i : indices) {
      curPlantTime += plantTime[i];
      result = max(result, curPlantTime + growTime[i]);
    }
    return result;
  }
};