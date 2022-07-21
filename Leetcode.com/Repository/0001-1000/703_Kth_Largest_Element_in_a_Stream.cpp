// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n)) for constructor(), O(log(k)) for add()
// space: O(n)

class KthLargest {
private:
  int m_Cap;
  vector<int> m_MinHeap;
  
  struct comp {
    bool operator()(const int& a, const int& b) {
      return a > b;
    }
  };
  
public:
  KthLargest(int k, vector<int>& nums) : m_Cap(k), m_MinHeap(nums) {
    make_heap(m_MinHeap.begin(), m_MinHeap.end(), comp());
    
    while (m_MinHeap.size() > k) {
      pop_heap(m_MinHeap.begin(), m_MinHeap.end(), comp());
      m_MinHeap.pop_back();
    }
  }
  
  int add(int val) {
    m_MinHeap.emplace_back(val);
    push_heap(m_MinHeap.begin(), m_MinHeap.end(), comp());
    
    if (m_MinHeap.size() > m_Cap) {
      pop_heap(m_MinHeap.begin(), m_MinHeap.end(), comp());
      m_MinHeap.pop_back();
    }
    
    return m_MinHeap.front();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */