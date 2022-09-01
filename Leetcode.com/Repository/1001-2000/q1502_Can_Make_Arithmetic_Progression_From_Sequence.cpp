// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting
class Sort {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    for (int i = 2; i < arr.size(); i++) {
      if (arr[i-2] - arr[i-1] != arr[i-1] - arr[i])
        return false;
    }
    return true;
  }
};

// time: O(n)
// space: O(n)
class Set {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    unordered_set<int> numSet;
    int first_min = INT_MAX, second_min = INT_MAX;
    bool hasSame = false;
    
    for (const int& num : arr) {
      if (numSet.count(num))
        hasSame = true;
      numSet.insert(num);
      
      if (num <= first_min) {
        second_min = first_min;
        first_min = num;
      }
      else if (num <= second_min)
        second_min = num;
    }
    
    int diff = second_min - first_min;
    if (diff == 0 and numSet.size() == 1)
      return true;
    
    if (hasSame)
      return false;
    
    for (int cur = first_min, i = 0; i < arr.size() - 1; i++) {
      if (numSet.count(cur + diff) == 0)
        return false;
      cur += diff;
    }
    
    return true;
  }
};