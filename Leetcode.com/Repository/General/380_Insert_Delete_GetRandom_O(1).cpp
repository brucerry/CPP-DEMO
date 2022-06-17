// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(1)
// space: O(n)

class RandomizedSet {
public:
  RandomizedSet() {
    
  }
  
  bool insert(int val) {
    if (numIndex.count(val))
      return false;
    numIndex[val] = buffer.size();
    buffer.emplace_back(val);
    return true;
  }
  
  bool remove(int val) {
    if (numIndex.count(val) == 0)
      return false;
    int i = numIndex[val];
    int lastVal = buffer.back();
    buffer[i] = lastVal;
    numIndex[lastVal] = i;
    buffer.pop_back();
    numIndex.erase(val);
    return true;
  }
  
  int getRandom() {
    return buffer[rand() % buffer.size()];
  }
  
private:
  vector<int> buffer;
  unordered_map<int, int> numIndex; // num, index
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */