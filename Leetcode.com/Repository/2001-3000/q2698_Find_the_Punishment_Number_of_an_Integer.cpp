// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

#include <string>
using namespace std;

// time: O(n * log(n) * 2^log(n))
// space: O(log(n))

class Solution {
public:    
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string sq = to_string(i * i);
            if (solve(sq, i, 0))
                res += i * i;
        }
        return res;
    }

private:
    bool solve(string& sq, int num, int start) {
        if (start == sq.size() and num == 0)
            return true;
        
        if (num < 0)
            return false;
        
        int prefix = 0;
        for (int i = start; i < sq.size(); i++) {
            prefix = prefix * 10 + sq[i] - '0';
            if (solve(sq, num - prefix, i + 1)) {
                return true;
            }
        }
        
        return false;
    }
};