// https://leetcode.com/problems/hand-of-straights/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize)
            return false;
        unordered_map<int, int> cnt;
        priority_queue<int, vector<int>, greater<>> minheap;
        for (int h : hand) {
            if (++cnt[h] == 1)
                minheap.emplace(h);
        }
        while (minheap.size()) {
            for (int num = minheap.top(), last = num + groupSize; num < last; ++num) {
                if (!cnt.contains(num))
                    return false;
                if (--cnt[num] == 0) {
                    if (minheap.top() != num)
                        return false;
                    minheap.pop();
                }
            }
        }
        return true;
    }
};