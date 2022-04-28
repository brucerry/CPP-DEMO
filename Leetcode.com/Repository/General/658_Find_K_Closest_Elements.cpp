// https://leetcode.com/problems/find-k-closest-elements/

#include <vector>
using namespace std;

// time: O(log(n-k) + k)
// space: O(1)
class Optimized {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0, r = arr.size() - k;
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      
      if (arr[m+k] - x < x - arr[m])
        l = m + 1;
      else
        r = m;
    }
    
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};

// time: O(log(n) + k)
// space: O(1)
class Intuitive {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int closest_index = 0, closest_x = arr[0];
    
    int l = 0, r = arr.size() - 1;
    
    // find the closest_index to x
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      int curDiff = abs(arr[m] - x);
      int resDiff = abs(closest_x - x);
      
      if (curDiff < resDiff or (curDiff == resDiff and arr[m] < closest_x)) {
        closest_index = m;
        closest_x = arr[m];
      }
      
      if (arr[m] < x)
        l = m + 1;
      else if (arr[m] > x)
        r = m - 1;
      else
        break;
    }
    
    l = r = closest_index;
    
    while (r - l + 1 < k) {
      if (l == 0)
        r++;
      else if (r == arr.size() - 1 or x - arr[l-1] <= arr[r+1] - x)
        l--;
      else
        r++;
    }
    
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};