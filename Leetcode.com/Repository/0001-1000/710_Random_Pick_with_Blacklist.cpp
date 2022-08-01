// https://leetcode.com/problems/random-pick-with-blacklist/

#include <vector>
#include <random>
#include <unordered_map>
using namespace std;

// b = size of blacklist
// time: O(b) for constructor, O(1) for pick()
// space: O(b)

class Solution {
public:
  Solution(int n, vector<int>& blacklist) {
    int whitelistSize = n - blacklist.size();
    
    for (const int& black : blacklist)
      blacklistMap[black] = -1;
    
    for (const int& black : blacklist) {
      if (black < whitelistSize) {
        while (blacklistMap.count(n - 1)) {
          blacklistMap.erase(n - 1);
          n--;
        }
        blacklistMap[black] = n - 1;
        n--;
      }
    }
    
    random_device rd;
    gen = mt19937(rd());
    distrib = uniform_int_distribution<int>(0, whitelistSize - 1);
  }
  
  int pick() {
    int val = distrib(gen);
    return blacklistMap.count(val) ? blacklistMap[val] : val;
  }
  
private:
  unordered_map<int, int> blacklistMap; // val, remapped val
  mt19937 gen;
  uniform_int_distribution<int> distrib;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */