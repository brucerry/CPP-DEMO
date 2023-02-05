// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

// time: O(n + k * log(n))
// space: O(1)

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(begin(gifts), end(gifts));
        while(k--) {
            pop_heap(begin(gifts), end(gifts));
            gifts.back() = sqrt(gifts.back());
            push_heap(begin(gifts), end(gifts));
        }
        return accumulate(begin(gifts), end(gifts), 0LL);
    }
};