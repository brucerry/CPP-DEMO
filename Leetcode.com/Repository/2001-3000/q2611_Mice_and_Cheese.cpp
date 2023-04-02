// https://leetcode.com/problems/mice-and-cheese/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int miceAndCheese(vector<int>& re1, vector<int>& re2, int k) {
        int res = 0, n = re1.size();
        for (int i = 0; i < n; i++) {
            re1[i] -= re2[i];
            res += re2[i];
        }
        nth_element(re1.begin(), re1.begin() + k, re1.end(), greater<>());
        return accumulate(re1.begin(), re1.begin() + k, res);
    }
};