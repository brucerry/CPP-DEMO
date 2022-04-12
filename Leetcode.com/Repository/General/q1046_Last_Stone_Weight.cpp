// https://leetcode.com/problems/last-stone-weight/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(1)

class Solution {  
public:
  int lastStoneWeight(vector<int>& stones) {
    make_heap(stones.begin(), stones.end());
    
    while (stones.size() >= 2) {
      int first = stones.front();
      
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      
      int second = stones.front();
      
      pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      
      int size = first - second;
      if (size) {
        stones.emplace_back(size);
        push_heap(stones.begin(), stones.end());
      }
    }
    
    return stones.size() ? stones.front() : 0;
  }
};