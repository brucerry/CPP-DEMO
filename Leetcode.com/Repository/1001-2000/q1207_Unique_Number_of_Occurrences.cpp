// https://leetcode.com/problems/unique-number-of-occurrences/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    int counts[2001] {}, freqs[1001] {};
    for (const int& num : arr) {
      counts[num + 1000]++;
    }
    for (const int& fq : counts) {
      if (fq and freqs[fq])
        return false;
      freqs[fq] = 1;
    }
    return true;
  }
};