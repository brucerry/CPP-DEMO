// https://leetcode.com/problems/distant-barcodes/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> numCount; // num, count
    for (const int& barcode : barcodes)
      numCount[barcode]++;
    
    priority_queue<pair<int, int>> maxHeap; // count, num
    for (const auto& [ num, count ] : numCount)
      maxHeap.emplace(count, num);
    
    int i = 0;
    vector<int> result (barcodes.size());
    pair<int, int> prev { 0, 0 }; // count, num
    while (maxHeap.size()) {
      auto [ count, num ] = maxHeap.top();
      maxHeap.pop();
      
      result[i++] = num;
      count--;
      
      if (prev.first) {
        maxHeap.emplace(prev);
        prev = { 0, 0 };
      }
      
      if (count)
        prev = { count, num };
    }
    
    return result;
  }
};