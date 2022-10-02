// https://leetcode.com/problems/longest-uploaded-prefix/

#include <set>
using namespace std;

// time: O(n)
// space: O(n)

class LUPrefix {
public:
  LUPrefix(int n) : len(0) {
    
  }
  
  void upload(int video) {
    uploaded.emplace(video);
    while (uploaded.count(len + 1))
      len++;
  }
  
  int longest() {
    return len;
  }

private:
  set<int> uploaded;
  int len;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */