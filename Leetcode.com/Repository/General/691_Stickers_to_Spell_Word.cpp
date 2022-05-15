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
    vector<vector<int>> stickerLetterCount (n, vector<int>(26));
    for (int sticker = 0; sticker < n; sticker++) {
      for (const char& c : stickers[sticker]) {
        stickerLetterCount[sticker][c - 'a']++;
      }
    }
    
    unordered_map<string, int> memo; // remain target, used stickers count
    return solve(stickerLetterCount, memo, target);
  }
  
private:
  int solve(vector<vector<int>>& stickerLetterCount, unordered_map<string, int>& memo, string& target) {
    if (target.size() == 0)
      return 0;
    
    if (memo.count(target))
      return memo[target];
    
    vector<int> targetLetterCount (26);
    for (const char& c : target)
      targetLetterCount[c - 'a']++;
    
    int n = stickerLetterCount.size();
    
    int result = INT_MAX;
    for (int sticker = 0; sticker < n; sticker++) {
      if (stickerLetterCount[sticker][target[0] - 'a'] == 0)
        continue;
      
      string remainTarget;
      for (int i = 0; i < 26; i++) {
        if (targetLetterCount[i] > stickerLetterCount[sticker][i])
          remainTarget += string(targetLetterCount[i] - stickerLetterCount[sticker][i], i + 'a');
      }
      
      int usedStickerCount = solve(stickerLetterCount, memo, remainTarget);
      if (usedStickerCount != -1)
        result = min(result, usedStickerCount + 1);
    }
    
    return memo[target] = result == INT_MAX ? -1 : result;
  }
};