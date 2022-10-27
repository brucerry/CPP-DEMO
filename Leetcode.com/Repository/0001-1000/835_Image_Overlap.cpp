// https://leetcode.com/problems/image-overlap/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^4)
// space: O(n^2)

class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int n = img1.size();
    
    vector<pair<int, int>> img1OnesCoord, img2OnesCoord;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (img1[r][c])
          img1OnesCoord.emplace_back(r, c);
        if (img2[r][c])
          img2OnesCoord.emplace_back(r, c);
      }
    }
    
    unordered_map<pair<int, int>, int, Hash> slideCount;
    for (const auto& [ r1, c1 ] : img1OnesCoord) {
      for (const auto& [ r2, c2 ] : img2OnesCoord) {
        slideCount[{ r1-r2, c1-c2 }]++;
      }
    }
    
    int overlap = 0;
    for (const auto& [ _, count ] : slideCount) {
      overlap = max(overlap, count);
    }
    
    return overlap;
  }
  
private:
  struct Hash {
    int operator()(const pair<int, int>& p) const {
      return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
  };
};