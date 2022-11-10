// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    auto it = upper_bound(letters.begin(), letters.end(), target);
    return it == letters.end() ? letters[0] : *it;
  }
};