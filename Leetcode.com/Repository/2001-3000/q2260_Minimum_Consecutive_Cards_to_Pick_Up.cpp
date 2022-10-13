// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Array {
public:
  int minimumCardPickup(vector<int>& cards) {
    int indices[1000001];
    fill(begin(indices), end(indices), -1);

    int result = INT_MAX;
    for (int i = 0; i < cards.size(); i++) {
      int val = cards[i];
      if (indices[val] != -1)
        result = min(result, i - indices[val] + 1);
      indices[val] = i;
    }
    return result == INT_MAX ? -1 : result;
  }
};

class HashMap {
public:
  int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> valIndex; // val, index
    int result = INT_MAX;
    for (int i = 0; i < cards.size(); i++) {
      int val = cards[i];
      if (valIndex.count(val))
        result = min(result, i - valIndex[val] + 1);
      valIndex[val] = i;
    }
    return result == INT_MAX ? -1 : result;
  }
};