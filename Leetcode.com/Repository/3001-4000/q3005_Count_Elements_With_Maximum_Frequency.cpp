// https://leetcode.com/problems/count-elements-with-maximum-frequency/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int maxf = 0, res = 0;
        for (auto& [ _, f ] : cnt) {
            if (f > maxf) {
                res = f;
                maxf = f;
            }
            else if (f == maxf) {
                res += f;
            }
        }
        return res;
    }
};