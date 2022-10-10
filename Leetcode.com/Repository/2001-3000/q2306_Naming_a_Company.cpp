// https://leetcode.com/problems/naming-a-company/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    unordered_set<string> suffixes[26];
    for (const string& idea : ideas) {
      suffixes[idea[0] - 'a'].emplace(idea.substr(1));
    }

    long result = 0;
    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        long cnt1 = 0, cnt2 = 0;
        for (const string& s : suffixes[i]) {
          if (suffixes[j].count(s) == 0)
            cnt1++;
        }
        for (const string& s : suffixes[j]) {
          if (suffixes[i].count(s) == 0)
            cnt2++;
        }
        result += cnt1 * cnt2 * 2;
      }
    }

    return result;
  }
};