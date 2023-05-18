// https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

#include <string>
#include <algorithm>
using namespace std;

// time: O(log(num))
// space: O(log(num))

class Solution {
public:
    long long smallestNumber(long long num) {
        long long abs_num = abs(num);
        string str = to_string(abs_num);
        if (num >= 0) {
            sort(str.begin(), str.end());
            if (str[0] == '0') {
                int i = upper_bound(str.begin(), str.end(), '0') - str.begin();
                if (i != str.size())
                    swap(str[0], str[i]);
            }
            return stoll(str);
        }
        sort(str.rbegin(), str.rend());
        return -stoll(str);
    }
};