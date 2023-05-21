// https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include <vector>
#include <string>
using namespace std;

// time: O(n * w)
// space: O(1)

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (string& word : words) {
            res += word.find(pref) == 0;
        }
        return res;
    }
};