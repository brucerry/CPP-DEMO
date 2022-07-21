// https://leetcode.com/problems/stickers-to-spell-word/

#include <vector>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;

// n = size of stickers
// s = len of each sticker
// t = len of target
// time: O(n * s + 2^t * n)
// space: O(n + 2^t)

class Solution {
public:
  int minStickers(vector<string>& stickers, string& target) {
    int n = stickers.size();
    
    vector<vector<int>> stickerCharCount (n, vector<int>(26));
    for (int i = 0; i < n; i++) {
      for (const char& c : stickers[i]) {
        stickerCharCount[i][c - 'a']++;
      }
    }
    
    unordered_map<string, int> memo; // remain target, min # of stickers
    return solve(target, stickerCharCount, memo);
  }
  
private:
  int solve(string& target, vector<vector<int>>& stickerCharCount, unordered_map<string, int>& memo) {
    if (target.length() == 0)
      return 0;
    
    if (memo.count(target))
      return memo[target];
    
    array<int, 26> targetCharCount { 0 };
    for (const char& c : target) {
      targetCharCount[c - 'a']++;
    }
    
    int result = INT_MAX;
    for (const auto& scc : stickerCharCount) {
      if (scc[target[0] - 'a'] == 0)
        continue;
      
      string remainTarget;
      for (int i = 0; i < 26; i++) {
        if (targetCharCount[i] > scc[i])
          remainTarget += string(targetCharCount[i] - scc[i], i + 'a');
      }
      
      int usedCount = solve(remainTarget, stickerCharCount, memo);
      if (usedCount != -1)
        result = min(result, 1 + usedCount);
    }
    
    return memo[target] = result == INT_MAX ? -1 : result;
  }
};