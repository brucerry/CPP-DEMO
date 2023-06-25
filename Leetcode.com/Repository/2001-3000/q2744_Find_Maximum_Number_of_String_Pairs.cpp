// https://leetcode.com/problems/find-maximum-number-of-string-pairs/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(26 * 26)

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int seen[1000] {}, res = 0;
        for (string& word : words) {
            res += seen[(word[1] - 'a') * 26 + word[0] - 'a'];
            seen[(word[0] - 'a') * 26 + word[1] - 'a'] = 1;
        }
        return res;
    }
};