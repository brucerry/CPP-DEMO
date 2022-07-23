// https://leetcode.com/problems/design-a-number-container-system/

#include <unordered_map>
#include <set>
using namespace std;

// time: O(log(n)) for change(), O(1) for find()
// space: O(n)

class NumberContainers {
public:
  NumberContainers() {
    
  }
  
  void change(int index, int number) {
    if (indexNum.count(index)) {
      int num = indexNum[index];
      numIndices[num].erase(index);
    }
    indexNum[index] = number;
    numIndices[number].insert(index);
  }
  
  int find(int number) {
    if (numIndices.count(number) and numIndices[number].size())
      return *numIndices[number].begin();
    return -1;
  }
  
private:
  unordered_map<int, int> indexNum; // index, num
  unordered_map<int, set<int>> numIndices; // num, indices
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */