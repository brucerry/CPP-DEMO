// https://leetcode.com/problems/number-of-recent-calls/

#include <queue>
using namespace std;

// time: O(n) in total
// space: O(n)

class RecentCounter {
public:
    queue<int> times;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        times.emplace(t);
        while (times.size() and times.front() < t - 3000) {
            times.pop();
        }
        return times.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */