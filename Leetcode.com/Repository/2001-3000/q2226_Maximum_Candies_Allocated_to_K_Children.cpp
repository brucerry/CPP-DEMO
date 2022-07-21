// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <vector>
using namespace std;

// time: O(n * log(sum(candies) / k))
// space: O(1)

class Solution {
public:
  int maximumCandies(vector<int>& candies, long long k) {    
    long l = 0, r = 0;
    for (const int& candy : candies) {
      r += candy;
    }
    r /= k;
    
    while (l < r) {
      int m = l + ((r - l + 1) >> 1);
      if (canGet(candies, k, m))
        l = m;
      else
        r = m - 1;
    }
    return l;
  }
  
private:
  bool canGet(vector<int>& candies, long long k, int everyoneCanGet) {
    long childCount = 0;
    for (const int& candy : candies) {
      childCount += candy / everyoneCanGet;
    }
    return childCount >= k;
  }
};