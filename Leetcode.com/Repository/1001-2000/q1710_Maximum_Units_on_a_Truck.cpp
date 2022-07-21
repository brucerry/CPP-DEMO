// https://leetcode.com/problems/maximum-units-on-a-truck/

#include <vector>
#include <array>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1001) => O(1)
class CountBoxes {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    array<int, 1001> units { 0 }; // index: numberOfUnitsPerBox, val: count of boxes
    for (const auto& type : boxTypes) {
      int numberOfBoxes = type[0];
      int numberOfUnitsPerBox = type[1];
      units[numberOfUnitsPerBox] += numberOfBoxes;
    }
    
    int unit = 0;
    for (int numberOfUnitsPerBox = 1000; numberOfUnitsPerBox >= 0 and truckSize; numberOfUnitsPerBox--) {
      int take = min(truckSize, units[numberOfUnitsPerBox]);
      unit += take * numberOfUnitsPerBox;
      truckSize -= take;
    }
    
    return unit;
  }
};

// time: O(n * log(n))
// space: O(log(n)) for sorting
class Sorting {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) -> bool {
      return a[1] > b[1];
    });
    
    int unit = 0;
    for (const auto& type : boxTypes) {
      int numberOfBoxes = type[0];
      int numberOfUnitsPerBox = type[1];
      int take = min(numberOfBoxes, truckSize);
      unit += take * numberOfUnitsPerBox;
      truckSize -= take;
      if (truckSize == 0)
        break;
    }
    
    return unit;
  }
};