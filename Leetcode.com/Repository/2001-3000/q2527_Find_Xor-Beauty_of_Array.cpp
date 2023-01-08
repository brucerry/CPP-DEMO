// https://leetcode.com/problems/find-xor-beauty-of-array/

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor());
    }
};