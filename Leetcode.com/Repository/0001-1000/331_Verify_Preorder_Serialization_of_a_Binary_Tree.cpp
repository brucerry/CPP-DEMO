// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include <sstream>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isValidSerialization(string& preorder) {    
    stringstream ss (preorder);
    string node;
    
    int slot = 1;
    while (getline(ss, node, ',')) {
      if (slot == 0)
        return false;
      slot += node == "#" ? -1 : 1;
    }
    return slot == 0;
  }
};