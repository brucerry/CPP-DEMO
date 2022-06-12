// https://leetcode.com/problems/boats-to-save-people/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    
    int boat = 0;
    int l = 0, r = people.size() - 1;
    while (l <= r) {
      int sum = people[l] + people[r];
      if (sum <= limit) {
        l++;
      }
      r--;
      boat++;
    }
    
    return boat;
  }
};