#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int positioningPlants(std::vector<std::vector<int>> costs, int pos, int prevType, unordered_map<string, int> &memo) {
  if (pos == costs.size()) return 0;
  string key = to_string(prevType) + ',' + to_string(pos);
  if (memo.count(key)) return memo[key];
  
  int minCost = -1;
  
  for (int type = 0; type < costs[0].size(); type++) {
    if (type != prevType) {
      int cost = costs[pos][type] + positioningPlants(costs, pos + 1, type, memo);
      if (minCost == -1 || cost < minCost) {
        minCost = cost;
      }
    }
  }
  
  memo[key] = minCost;
  return memo[key];
}

int positioningPlants(std::vector<std::vector<int>> costs) {  
  unordered_map<string, int> memo;
  return positioningPlants(costs, 0, -1, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}