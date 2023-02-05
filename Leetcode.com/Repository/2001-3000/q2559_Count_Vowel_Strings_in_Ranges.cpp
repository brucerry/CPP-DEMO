// https://leetcode.com/problems/count-vowel-strings-in-ranges/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// n = size of words
// q = size of queries
// time: O(n + q)
// space: O(n)

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        vector<int> buffer;
        for (const string& w : words) {
            buffer.emplace_back(vowels.count(w.front()) and vowels.count(w.back()));
        }
        for (int i = 1; i < buffer.size(); i++) {
            buffer[i] += buffer[i-1];
        }
        vector<int> res;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            res.emplace_back(buffer[r] - (l ? buffer[l-1] : 0));
        }
        return res;
    }
};