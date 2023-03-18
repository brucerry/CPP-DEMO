// https://leetcode.com/problems/design-browser-history/

#include <string>
#include <vector>
using namespace std;

// time: O(1) for each method
// space: O(n)

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        cur = last = 0;
        history = { homepage };
    }
    
    void visit(string url) {
        cur++;
        if (cur == history.size())
            history.emplace_back(url);
        else
            history[cur] = url;
        last = cur;
    }
    
    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }
    
    string forward(int steps) {
        cur = min(last, cur + steps);
        return history[cur];
    }

private:
    int cur, last;
    vector<string> history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */