// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/

#include <string>
#include <vector>
using namespace std;

// n = max(s + a, s + b, a + b)
// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ka = kmp(s, a);
        vector<int> kb = kmp(s, b);
        vector<int> res;
        for (int i = 0, j = 0; i < ka.size(); i++) {
            while (j < kb.size() and ka[i] - kb[j] > k) {
                j++;
            }
            if (j < kb.size() and abs(ka[i] - kb[j]) <= k)
                res.emplace_back(ka[i]);
        }
        return res;
    }
    
    vector<int> kmp(string& s, string& sub) {
        string tmp = sub + '#' + s;
        vector<int> dp (tmp.size());
        for (int i = 1; i < tmp.size(); i++) {
            int cur = dp[i - 1];
            while (cur and tmp[i] != tmp[cur]) {
                cur = dp[cur - 1];
            }
            dp[i] = cur + (tmp[i] == tmp[cur]);
        }
        vector<int> k;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] >= sub.size()) {
                k.emplace_back(i - 2 * sub.size());
            }
        }
        return k;
    }
};