// https://leetcode.com/problems/reduce-array-size-to-the-half/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)
class RecordFrequency {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : arr)
      numCount[num]++;
    
    int n = arr.size();
    vector<int> freqs (n + 1);
    for (const auto& [ _, count ] : numCount)
      freqs[count]++;
    
    int setSize = 0;
    for (int freq = n, sum = 0, half = n / 2; freq and sum < half; freq--) {
      while (sum < half and freqs[freq]) {
        sum += freq;
        freqs[freq]--;
        setSize++;
      }
    }
    
    return setSize;
  }
};

// time: O(n * log(n))
// space: O(n)
class MaxHeap {
public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> numCount; // num, count
    for (const int& num : arr)
      numCount[num]++;
    
    priority_queue<int> maxHeap; // count
    for (const auto& [ _, count ] : numCount)
      maxHeap.emplace(count);
    
    int n = arr.size(), half = n / 2;
    int sum = 0, setSize = 0;
    while (maxHeap.size() and sum < half) {
      int count = maxHeap.top();
      maxHeap.pop();
      sum += count;
      setSize++;
    }
    
    return setSize;
  }
};