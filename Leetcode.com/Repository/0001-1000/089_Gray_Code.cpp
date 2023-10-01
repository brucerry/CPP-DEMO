// https://leetcode.com/problems/gray-code/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res { 0 };
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.emplace_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};