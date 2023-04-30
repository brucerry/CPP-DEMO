// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common = 0;
        vector<int> res (n), count (n + 1);
        for (int i = 0; i < A.size(); i++) {
            if (++count[A[i]] == 2)
                common++;
            if (++count[B[i]] == 2)
                common++;
            res[i] = common;
        }
        return res;
    }
};