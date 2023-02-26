// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long cursum = 0;
        for (char ch : word) {
            int digit = ch - '0';
            cursum = cursum * 10 + digit;
            int remain = cursum % m;
            res.emplace_back(remain == 0);
            cursum = remain;
        }
        return res;
    }
};