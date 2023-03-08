// https://leetcode.com/problems/kth-missing-positive-number/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = (l + r) / 2;
            int miss = arr[m] - (m + 1);
            if (miss >= k)
                r = m;
            else
                l = m + 1;
        }
        return r + k;
    }
};