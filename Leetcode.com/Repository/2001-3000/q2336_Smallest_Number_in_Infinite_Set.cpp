// https://leetcode.com/problems/smallest-number-in-infinite-set/

#include <set>
using namespace std;

// time: O(log(n))
// space: O(n)

class SmallestInfiniteSet {
public:
    set<int> set;
    int largest;

    SmallestInfiniteSet() {
        set = { 1 };
        largest = 1;
    }
    
    int popSmallest() {
        int val = *set.begin();
        set.erase(val);
        
        if (val == largest)
            set.emplace(++largest);
        
        return val;
    }
    
    void addBack(int num) {
        set.emplace(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */