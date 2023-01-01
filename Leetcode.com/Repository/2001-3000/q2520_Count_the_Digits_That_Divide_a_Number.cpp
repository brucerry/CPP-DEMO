// https://leetcode.com/problems/count-the-digits-that-divide-a-number/

// time: O(log(num))
// space: O(1)

class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int copy = num; copy; copy /= 10) {
            if (num % (copy % 10) == 0)
                res++;
        }
        return res;
    }
};