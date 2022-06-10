// https://leetcode.com/problems/detect-squares/

#include <vector>
#include <unordered_map>
using namespace std;

// n = # of points(x, y)
// time: O(1) for add(), O(n) for count()
// space: O(n)

class DetectSquares {
public:
  DetectSquares() {
    
  }
  
  void add(vector<int> point) {
    int px = point[0];
    int py = point[1];
    pointCount[{ px, py }]++;
  }
  
  int count(vector<int> point) {
    int px = point[0];
    int py = point[1];
    
    int square = 0;
    for (const auto& [ p, cnt ] : pointCount) {
      auto& [ x, y ] = p;
      if (x != px and y != py and abs(x - px) == abs(y - py) and pointCount.count({ x, py }) and pointCount.count({ px, y }))
        square += cnt * pointCount[{ x, py }] * pointCount[{ px, y }];
    }
    
    return square;
  }
  
private:
  struct Hash {
    int operator()(const pair<int, int>& p) const {
      return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
  };
  
  unordered_map<pair<int, int>, int, Hash> pointCount;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */