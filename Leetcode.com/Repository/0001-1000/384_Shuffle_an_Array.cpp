// https://leetcode.com/problems/shuffle-an-array/

#include <vector>
#include <cstdlib>
using namespace std;

// time: O(n) for constructor and shuffle(), O(1) for reset()
// space: O(n)

class Solution {
public:
  Solution(vector<int>& nums) : original(nums) {
    
  }
  
  vector<int> reset() {
    return original;
  }
  
  vector<int> shuffle() {
    vector<int> result = original;
    int n = result.size();
    for (int i = 0; i < n; i++) {
      int j = rand() % (n - i) + i;
      swap(result[i], result[j]);
    }
    return result;
  }
  
private:
  vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */