// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        int res = 0;
        for (int i = left; i <= right; i++) {
            const string& word = words[i];
            res += vowels.count(word.front()) and vowels.count(word.back());
        }
        return res;
    }
};