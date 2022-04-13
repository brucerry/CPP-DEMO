// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
using namespace std;

// time: O(log(n)) for addNum(), O(1) for findMedian()
// space: O(n)

class MedianFinder {
private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;

public:
  MedianFinder() {
    
  }
    
  void addNum(int num) {
    maxHeap.emplace(num);

    if (minHeap.size() && maxHeap.top() > minHeap.top()) {
      minHeap.emplace(maxHeap.top());
      maxHeap.pop();
    }

    if (maxHeap.size() == minHeap.size() + 2) {
      minHeap.emplace(maxHeap.top());
      maxHeap.pop();
    }

    if (minHeap.size() == maxHeap.size() + 2) {
      maxHeap.emplace(minHeap.top());
      minHeap.pop();
    }
  }
    
  double findMedian() {
    if (maxHeap.size() > minHeap.size())
      return maxHeap.top();

    if (maxHeap.size() < minHeap.size())
      return minHeap.top();

    return (maxHeap.top() + minHeap.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */