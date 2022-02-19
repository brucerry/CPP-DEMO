// https://leetcode.com/problems/find-k-closest-elements/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // time: O(log(n-k) + k)
  // space: O(1)
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (x - arr[mid] > arr[mid+k] - x) left = mid + 1;
      else right = mid;
    }

    return vector<int>(arr.begin() + left, arr.begin() + left + k);
  }

  // time: O(log(n) + k)
  // space: O(1)
  // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  //   // lower_bound() does work too
  //   int ubPos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

  //   //cout << ubPos << endl;

  //   if (ubPos == arr.size()) { // x is too large
  //     return vector<int>(arr.end() - k, arr.end());
  //   } else if (ubPos == 0) { // x is too small
  //     return vector<int>(arr.begin(), arr.begin() + k);
  //   } else {
  //     int left, right;
  //     if (abs(arr[ubPos-1] - x) <= abs(arr[ubPos] - x)) {
  //       left = right = ubPos - 1;
  //     } else {
  //       left = right = ubPos;
  //     }
  //     while (right - left + 1 < k) {
  //       if (left == 0) right++;
  //       else if (right == arr.size() - 1) left--;
  //       else {
  //         if (abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) {
  //           left--;
  //         } else {
  //           right++;
  //         }
  //       }
  //     }
  //     return vector<int>(arr.begin() + left, arr.begin() + left + k);
  //   }
  // }
};