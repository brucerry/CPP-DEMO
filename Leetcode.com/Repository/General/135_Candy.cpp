// https://leetcode.com/problems/candy/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  int candy(vector<int>& ratings) {
    int need = 1, up = 0, down = 0, peak = 0;
    for (int i = 1; i < ratings.size(); i++) {
      if (ratings[i-1] < ratings[i]) {
        up++;
        down = 0;
        peak = up;
        need += up + 1;
      }
      else if (ratings[i-1] > ratings[i]) {
        up = 0;
        down++;
        need += down + (down > peak);
      }
      else {
        up = down = peak = 0;
        need++;
      }
    }
    return need;
  }
};

// time: O(n)
// space: O(n)
class ScanLeftRight {
public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies (n, 1);
    
    for (int i = 1; i < n; i++) {
      if (ratings[i-1] < ratings[i])
        candies[i] = max(candies[i], candies[i-1] + 1);
    }
    
    int need = candies.back();
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1])
        candies[i] = max(candies[i], candies[i+1] + 1);
      need += candies[i];
    }
    
    return need;
  }
};