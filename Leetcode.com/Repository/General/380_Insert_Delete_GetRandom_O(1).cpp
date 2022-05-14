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
    
    nums.emplace_back(val);
    numIndex[val] = nums.size() - 1;
    return true;
  }
  
  bool remove(int val) {
    if (numIndex.count(val) == 0)
      return false;
    
    int i = numIndex[val];
    int lastVal = nums.back();
    nums[i] = lastVal;
    numIndex[lastVal] = i;
    nums.pop_back();
    numIndex.erase(val);
    return true;
  }
  
  int getRandom() {
    int i = rand() % nums.size();
    return nums[i];
  }
  
private:  
  unordered_map<int, int> numIndex; // num, index
  vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */