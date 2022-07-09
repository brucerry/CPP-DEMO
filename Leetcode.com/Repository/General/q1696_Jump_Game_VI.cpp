// https://leetcode.com/problems/jump-game-vi/

#include <vector>
#include <deque>
using namespace std;

// time: O(n)
// space: O(k)
class DequeStoresPair {
public:
  int maxResult(vector<int>& nums, int k) {
    deque<pair<int, int>> deque; // index, score
    for (int i = 0; i < nums.size(); i++) {
      if (deque.size() and deque.front().first < i - k)
        deque.pop_front();
      
      int score = nums[i] + (deque.size() ? deque.front().second : 0);
      while (deque.size() and deque.back().second <= score)
        deque.pop_back();
      deque.emplace_back(i, score);
    }
    return deque.back().second;
  }
};

// time: O(n)
// space: O(k)
class DequeStoresIndex {
public:
  int maxResult(vector<int>& nums, int k) {
    deque<int> deque; // index
    for (int i = 0; i < nums.size(); i++) {
      if (deque.size() and deque.front() < i - k)
        deque.pop_front();
      
      nums[i] = nums[i] + (deque.size() ? nums[deque.front()] : 0);
      while (deque.size() and nums[deque.back()] <= nums[i])
        deque.pop_back();
      deque.emplace_back(i);
    }
    return nums.back();
  }
};