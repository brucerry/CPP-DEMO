// https://leetcode.com/problems/count-number-of-teams/

#include <vector>
#include <set>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int numTeams(vector<int>& rating) {
    int n = rating.size();
    set<int> left, right (rating.begin(), rating.end());
    
    int team = 0, root = 0;
    for (const int& rate : rating) {
      if (root)
        left.insert(root);
      root = rate;
      right.erase(root);
      int leftLess = distance(left.begin(), left.lower_bound(root));
      int rightGreater = distance(right.lower_bound(root), right.end());
      int leftGreater = left.size() - leftLess;
      int rightLess = right.size() - rightGreater;
      team += leftLess * rightGreater + rightLess * leftGreater;
    }
    
    return team;
  }
};