// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

// n = size of nums
// d = size of numsDivide
// gcd = log(max(numsDivide))
// time: O(n + d * gcd)
class GCD {
public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int GCD = numsDivide[0];
    for (int div : numsDivide) {
      GCD = gcd(GCD, div);
    }
    
    int smallestDivisible = INT_MAX;
    for (const int& num : nums) {
      if (GCD % num == 0)
        smallestDivisible = min(smallestDivisible, num);
    }
    
    return smallestDivisible == INT_MAX ? -1 : count_if(nums.begin(), nums.end(), [&](const int& num) -> bool {
      return num < smallestDivisible;
    });
  }
};

// n = size of nums
// d = size of numsDivide
// gcd = log(max(numsDivide))
// time: O(n * log(n) + d * gcd)
class GCDwithSorting {
public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int GCD = numsDivide[0];
    for (int div : numsDivide) {
      // GCD = gcd(GCD, div);
      while (div) {
        int remain = GCD % div;
        GCD = div;
        div = remain;
      }
    }
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() and nums[i] <= GCD; i++) {
      if (GCD % nums[i] == 0)
        return i;
    }
    
    return -1;
  }
};

// n = size of nums
// d = size of numsDivide
// time: O(n * log(n) + d)
// space: O(n)
class GreedyMap {
public:
  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    map<int, int> numCount; // num, count
    for (const int& num : nums) {
      numCount[num]++;
    }
    
    int del = 0, i = 0;
    auto mapIt = numCount.begin();
    while (i < numsDivide.size() and mapIt != numCount.end()) {
      while (numsDivide[i] % mapIt->first) {
        del += mapIt->second;
        mapIt++;
        if (mapIt == numCount.end())
          return -1;
      }
      i++;
    }
    
    return del;
  }
};