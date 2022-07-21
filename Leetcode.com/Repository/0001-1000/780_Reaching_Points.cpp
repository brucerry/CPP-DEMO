// https://leetcode.com/problems/reaching-points/

// time: O(log(min(tx, ty)))
// space: O(1)

class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (true) {
      if ((sx == tx and sy <= ty and (ty - sy) % sx == 0) or
          (sy == ty and sx <= tx and (tx - sx) % sy == 0))
        return true;
      if (sx > tx or sy > ty)
        return false;
      
      if (tx > ty)
        tx %= ty;
      else
        ty %= tx;
    }
  }
};