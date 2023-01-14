// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#include <string>
using namespace std;

// n = len of s1 = len of s2
// m = len of baseStr
// time: O(n + m)
// space: O(1)

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), parents[26];
        for (int i = 0; i < 26; i++) {
            parents[i] = i;
        }
        for (int i = 0; i < n; i++) {
            unions(parents, s1[i] - 'a', s2[i] - 'a');
        }
        for (char& c : baseStr) {
            c = find(parents, parents[c - 'a']) + 'a';
        }
        return baseStr;
    }

private:
    char find(int* parents, char c) {
        return c == parents[c] ? c : parents[c] = find(parents, parents[c]);
    }

    void unions(int* parents, char c1, char c2) {
        char p1 = find(parents, c1);
        char p2 = find(parents, c2);
        parents[max(p1, p2)] = min(p1, p2);
    }
};