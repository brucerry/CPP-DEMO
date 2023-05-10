// https://leetcode.com/problems/dinner-plate-stacks/

#include <set>
#include <map>
#include <stack>
using namespace std;

// time: O(1) for constructor, O(log(n)) for push(), pop(), popAtStack()
// space: O(n)

class DinnerPlates {
public:
    int cap;
    set<int> available; // available stack index
    map<int, stack<int>> mstack; // index, stack

    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (available.size() == 0) {
            available.insert(mstack.size());
        }
        int i = *available.begin();
        mstack[i].push(val);
        if (mstack[i].size() == cap) {
            available.erase(i);
        }
    }
    
    int pop() {
        while (mstack.size() and mstack.rbegin()->second.size() == 0) {
            mstack.erase(mstack.rbegin()->first);
        }
        if (mstack.size() == 0) {
            return -1;
        }
        return popAtStack(mstack.rbegin()->first);
    }
    
    int popAtStack(int index) {
        if (mstack.count(index) == 0 or mstack[index].size() == 0)
            return -1;
        int res = mstack[index].top();
        mstack[index].pop();
        available.insert(index);
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */