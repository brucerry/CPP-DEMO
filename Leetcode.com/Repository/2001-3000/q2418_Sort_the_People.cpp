// https://leetcode.com/problems/sort-the-people/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> pairs;
    for (int i = 0; i < names.size(); i++) {
      pairs.emplace_back(heights[i], names[i]);
    }
    sort(pairs.rbegin(), pairs.rend());

    for (int i = 0; i < names.size(); i++) {
      names[i] = pairs[i].second;
    }

    return names;
  }
};