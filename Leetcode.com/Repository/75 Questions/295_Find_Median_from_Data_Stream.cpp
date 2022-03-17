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
    maxHeap.push(num);

    if (maxHeap.size() && minHeap.size() && maxHeap.top() > minHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }

    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }

    if (minHeap.size() > maxHeap.size() + 1) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }
    
  double findMedian() {
    if (maxHeap.size() == minHeap.size()) {
      return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    if (maxHeap.size() > minHeap.size()) {
      return maxHeap.top();
    }
    return minHeap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */