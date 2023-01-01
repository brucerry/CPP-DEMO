// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minimumPartition(string s, int k) {
        long res = 1, sub = 0;
        for (const char& c : s) {
            int d = c - '0';
            if (sub * 10 + d > k) {
                sub = 0;
                res++;
            }
            sub = sub * 10 + d;
            if (sub > k)
                return -1;
        }
        return res;
    }
};