// https://leetcode.com/problems/most-profit-assigning-work/

#include <vector>
#include <map>
using namespace std;

// n = size of difficulty and profit
// w = size of worker
// time: O(n * log(n) + w * log(n))
// space: O(n)

class Solution {
public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    map<int, int> map; // difficulty[i], profit[i]
    for (int i = 0; i < difficulty.size(); i++) {
      map[difficulty[i]] = max(map[difficulty[i]], profit[i]);
    }

    for (auto it = ++map.begin(); it != map.end(); it++) {
      it->second = max(it->second, prev(it)->second);
    }

    int result = 0;
    for (const int& ability : worker) {
      auto it = map.upper_bound(ability);
      result += it == map.begin() ? 0 : prev(it)->second;
    }

    return result;
  }
};