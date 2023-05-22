// https://leetcode.com/problems/sort-the-jumbled-numbers/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), [&](int a, int b) {
            return mapped_value(mapping, a) < mapped_value(mapping, b);
        });
        return nums;
    }

private:
    int mapped_value(vector<int>& mapping, int num) {
        if (num == 0)
            return mapping[0];

        int value = 0, pow = 1;
        while (num) {
            value += mapping[num % 10] * pow;
            pow *= 10;
            num /= 10;
        }
        return value;
    }
};