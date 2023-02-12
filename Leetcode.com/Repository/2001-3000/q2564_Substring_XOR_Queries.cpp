// https://leetcode.com/problems/substring-xor-queries/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// s = len of s
// q = size of queries
// time: O(s + q)
// space: O(s)

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        unordered_map<int, vector<int>> ValPair;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = i; j < min(n, i+30); j++) {
                val = (val << 1) + s[j] - '0';
                if (ValPair.count(val) == 0 or j - i < ValPair[val][1] - ValPair[val][0])
                    ValPair[val] = { i, j };
            }
        }
        
        vector<vector<int>> res;
        for (const auto& q : queries) {
            int val = q[0] ^ q[1];
            res.push_back(ValPair.count(val) ? ValPair[val] : vector<int>{ -1, -1 });
        }
        
        return res;
    }
};