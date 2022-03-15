// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <vector>
using namespace std;

// time: O(e * k)
// space: O(n)

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prices (n, INT_MAX);
    prices[src] = 0;

    vector<int> tmp;

    for (int i = 0; i < k + 1; i++) {
      tmp = prices;

      for (auto& flight : flights) {
        int s = flight[0];
        int d = flight[1];
        int p = flight[2];

        if (prices[s] == INT_MAX) continue;

        tmp[d] = min(tmp[d], prices[s] + p);
      }

      prices = tmp;
    }

    return prices[dst] == INT_MAX ? -1 : prices[dst];
  }
};