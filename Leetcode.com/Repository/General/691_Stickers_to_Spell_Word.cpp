// https://leetcode.com/problems/stickers-to-spell-word/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// s = size of stickers
// t = len of target
// time: O(2^t * s)
// space: O(t)

class Solution {
public:
  int minStickers(vector<string>& stickers, string& target) {
    int n = stickers.size();
    
    vector<vector<int>> stickersCharCount (n, vector<int>(26));
    for (int sticker = 0; sticker < n; sticker++) {
      for (const char& c : stickers[sticker])
        stickersCharCount[sticker][c - 'a']++;
    }
    
    unordered_map<string, int> memo; // remain target, used stickers count
    return solve(target, stickersCharCount, memo);
  }
  
private:
  int solve(string& target, vector<vector<int>>& stickersCharCount, unordered_map<string, int>& memo) {
    if (target.length() == 0)
      return 0;
    
    if (memo.count(target))
      return memo[target];
    
    vector<int> targetCharCount (26);
    for (const char& c : target)
      targetCharCount[c - 'a']++;
    
    int result = INT_MAX;
    for (const auto& charCount : stickersCharCount) {
      if (charCount[target[0] - 'a'] == 0)
        continue;
      
      string remainTarget;
      for (int i = 0; i < 26; i++) {
        if (targetCharCount[i] > charCount[i])
          remainTarget += string(targetCharCount[i] - charCount[i], i + 'a');
      }
      
      int usedStickersCount = solve(remainTarget, stickersCharCount, memo);
      if (usedStickersCount != -1)
        result = min(result, usedStickersCount + 1);
    }
    
    return memo[target] = result == INT_MAX ? -1 : result; 
  }
};