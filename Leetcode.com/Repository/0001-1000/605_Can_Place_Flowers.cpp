// https://leetcode.com/problems/can-place-flowers/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size() and n; i++) {
      if (flowerbed[i] == 0) {
        bool leftEmpty = i == 0 or flowerbed[i-1] == 0;
        bool rightEmpty = i == flowerbed.size() - 1 or flowerbed[i+1] == 0;
        if (leftEmpty and rightEmpty) {
          flowerbed[i] = 1;
          n--;
        }
      }
    }
    
    return n == 0;
  }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);
        for (int i = 1; i <= size; i++) {
            if (flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};