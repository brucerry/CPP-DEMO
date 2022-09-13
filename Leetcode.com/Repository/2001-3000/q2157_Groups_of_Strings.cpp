// https://leetcode.com/problems/groups-of-strings/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n * 26 * 26)
// space: O(n)

class Solution {
public:
  vector<int> groupStrings(vector<string>& words) {
    unordered_map<int, int> maskCount; // mask, count
    for (const string& word : words) {
      int mask = 0;
      for (const char& c : word) {
        mask |= 1 << (c - 'a');
      }
      maskCount[mask]++;
    }
    
    int groups = 0, maxSize = 0;
    while (maskCount.size()) {
      int size = makeGroup(maskCount, maskCount.begin()->first);
      maxSize = max(maxSize, size);
      groups += size > 0;
    }
    
    return { groups, maxSize };
  }
  
private:
  int makeGroup(unordered_map<int, int>& maskCount, int mask) {
    int groupSize = 0;
    if (maskCount.count(mask)) {
      groupSize += maskCount[mask];
      maskCount.erase(mask);
      for (int i = 0; i < 26; i++) {
        groupSize += makeGroup(maskCount, mask ^ (1 << i)); // add or delete 1 letter
        for (int j = i + 1; j < 26; j++) {
          if (((mask >> i) & 1) != ((mask >> j) & 1)) // replace 1 letter only in case of bit_i is different from bit_j
            groupSize += makeGroup(maskCount, mask ^ (1 << i) ^ (1 << j));
        }
      }
    }
    return groupSize;
  }
};