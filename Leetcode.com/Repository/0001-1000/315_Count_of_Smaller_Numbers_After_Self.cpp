// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <vector>
using namespace std;

// time: O(n * log(n))
// space: O(n)

struct Info {
    int val, index;
    Info() {}
    Info(int v, int i) : val(v), index(i) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Info> info (n), tmp(n);
        for (int i = 0; i < n; i++) {
            info[i] = { nums[i], i };
        }
        vector<int> res (n);
        solve(info, tmp, res, 0, n - 1);
        return res;
    }

private:
    void solve(vector<Info>& info, vector<Info>& tmp, vector<int>& res, int left, int right) {
        if (right - left + 1 <= 1)
            return;
        
        int mid = (left + right) / 2;
        solve(info, tmp, res, left, mid);
        solve(info, tmp, res, mid + 1, right);

        int l = left, r = mid + 1, ptr = left;
        int count = 0;
        while (l <= mid or r <= right) {
            if (l > mid) {
                tmp[ptr] = info[r++];
            }
            else if (r > right) {
                tmp[ptr] = info[l++];
                res[tmp[ptr].index] += count;
            }
            else if (info[l].val <= info[r].val) {
                tmp[ptr] = info[l++];
                res[tmp[ptr].index] += count;
            }
            else {
                tmp[ptr] = info[r++];
                count++;
            }
            ptr++;
        }

        for (int i = left; i <= right; i++) {
            info[i] = tmp[i];
        }
    }
};