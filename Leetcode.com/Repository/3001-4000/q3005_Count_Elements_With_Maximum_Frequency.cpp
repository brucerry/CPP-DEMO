// https://leetcode.com/problems/count-elements-with-maximum-frequency/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int res = 0, maxf = 0;
        int cnt[101] {};
        for (int num : nums) {
            ++cnt[num];
            if (cnt[num] > maxf)
                res = maxf = cnt[num];
            else if (cnt[num] == maxf)
                res += maxf;
        }
        return res;
    }
};