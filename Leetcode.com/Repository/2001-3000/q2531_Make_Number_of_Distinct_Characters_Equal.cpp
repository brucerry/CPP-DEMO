// https://leetcode.com/problems/make-number-of-distinct-characters-equal/

#include <string>
using namespace std;

// time: O(m + n)
// space: O(1)

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int cnt1[26] {}, cnt2[26] {};
        for (const char& c : word1) {
            cnt1[c - 'a']++;
        }
        for (const char& c : word2) {
            cnt2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt1[i] and cnt2[j]) {
                    cnt1[i]--;
                    cnt2[j]--;
                    cnt1[j]++;
                    cnt2[i]++;
                    if (countDistinct(cnt1) == countDistinct(cnt2))
                        return true;
                    cnt1[i]++;
                    cnt2[j]++;
                    cnt1[j]--;
                    cnt2[i]--;
                }
            }
        }
        return false;
    }

private:
    int countDistinct(int* cnt) {
        int dist = 0;
        for (int i = 0; i < 26; i++) {
            dist += cnt[i] > 0;
        }
        return dist;
    }
};