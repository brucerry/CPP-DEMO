// https://leetcode.com/problems/count-operations-to-obtain-zero/

// time: O(max(num1, num2))
// space: O(1)

class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        while (num1 and num2) {
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;
            res++;
        }
        return res;
    }
};