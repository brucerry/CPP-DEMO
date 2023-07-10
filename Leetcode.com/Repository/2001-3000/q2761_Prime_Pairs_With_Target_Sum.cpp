// https://leetcode.com/problems/prime-pairs-with-target-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> isprime (n + 1, true);
        for (int f = 2; f * f <= n; f++) {
            if (isprime[f]) {
                for (int x = f * f; x <= n; x += f) {
                    isprime[x] = false;
                }
            }
        }
        
        vector<vector<int>> res;
        for (int f = 2; f * 2 <= n; f++) {
            if (isprime[f] and isprime[n-f])
                res.push_back({ f, n - f });
        }
        
        return res;
    }
};