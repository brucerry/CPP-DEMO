// https://leetcode.com/problems/design-memory-allocator/

#include <vector>
using namespace std;

// time: O(n) for constructor, allocate(), free()
// space: O(n)

class Allocator {
public:
  Allocator(int n) {
    mem.resize(n);
  }
  
  int allocate(int size, int mID) {
    int freeMem = 0;
    for (int i = 0; i < mem.size(); i++) {
      if (mem[i] == 0) {
        if (++freeMem == size) {
          int start = i - size + 1;
          for (int j = start; j < start + size; j++) {
            mem[j] = mID;
          }
          return start;
        }
      }
      else if (freeMem < size) {
        freeMem = 0;
      }
    }
    return -1;
  }
  
  int free(int mID) {
    int freed = 0;
    for (int& id : mem) {
      if (id == mID) {
        freed++;
        id = 0;
      }
    }
    return freed;
  }

private:
  vector<int> mem;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */