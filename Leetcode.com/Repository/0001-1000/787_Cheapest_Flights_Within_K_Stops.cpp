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
    
    for (int i = 0; i <= k; i++) {
      vector<int> tmp = prices;
      
      for (const auto& flight : flights) {
        int from = flight[0];
        int to = flight[1];
        int price = flight[2];
        
        if (prices[from] == INT_MAX)
          continue;
        
        tmp[to] = min(tmp[to], prices[from] + price);
      }
      
      prices = tmp;
    }
    
    return prices[dst] == INT_MAX ? -1 : prices[dst];
  }
};