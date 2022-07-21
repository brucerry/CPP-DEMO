// https://leetcode.com/problems/smallest-number-in-infinite-set/

#include <set>
using namespace std;

// time: O(log(n))
// space: O(n)

class SmallestInfiniteSet {
public:
  SmallestInfiniteSet() : largest(1) {
    curSet.insert(1);
  }
  
  int popSmallest() {
    int val = *curSet.begin();
    curSet.erase(val);
    
    if (val == largest)
      curSet.insert(++largest);
    
    return val;
  }
  
  void addBack(int num) {
    curSet.insert(num);
  }
  
private:
  set<int> curSet;
  int largest;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */