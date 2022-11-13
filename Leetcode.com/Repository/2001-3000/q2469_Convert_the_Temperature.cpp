// https://leetcode.com/problems/convert-the-temperature/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  vector<double> convertTemperature(double celsius) {
    return { celsius + 273.15, celsius * 1.8 + 32.0 };
  }
};