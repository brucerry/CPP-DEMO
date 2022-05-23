// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// t = size of tasks
// time: O(t + 26 * log(26)) => O(t)
// space: O(26) => O(1)
class MaxHeapSolution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    array<int, 26> charCount { 0 };
    for (const char& c : tasks)
      charCount[c - 'A']++;
    
    priority_queue<int> ready; // count
    for (const int& count : charCount) {
      if (count)
        ready.emplace(count);
    }
    
    queue<pair<int, int>> cooldown; // ready time, count
    
    int curTime = 0;
    while (ready.size() or cooldown.size()) {
      if (ready.size()) {
        int count = ready.top();
        ready.pop();
        if (--count)
          cooldown.emplace(curTime + n, count);
      }
      
      if (cooldown.size()) {
        auto [ readytime, count ] = cooldown.front();
        if (readytime == curTime) {
          ready.emplace(count);
          cooldown.pop();
        }
      }
      
      if (ready.size() or cooldown.size() == 0)
        curTime++;
      else
        curTime = cooldown.front().first;
    }
    
    return curTime;
  }
};

// t = size of tasks
// time: O(t)
// space: O(26) => O(1)
class MathsSolution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    int maxFreq = 0, maxFreqCount = 0;
    
    array<int, 26> charCount { 0 };
    for (const char& c : tasks) {
      charCount[c - 'A']++;
      
      if (charCount[c - 'A'] > maxFreq) {
        maxFreq = charCount[c - 'A'];
        maxFreqCount = 1;
      }
      else if (charCount[c - 'A'] == maxFreq)
        maxFreqCount++;
    }
    
    int gapCount = maxFreq - 1; // # of gap between maxFreq tasks group
    int gapLen = n - (maxFreqCount - 1); // length of each gap
    int emptySlots = gapCount * gapLen; // # of empty slots that can be assigned to non-maxFreq tasks
    int availableTasks = tasks.size() - maxFreq * maxFreqCount; // # of non-maxFreq tasks
    int idles = max(0, emptySlots - availableTasks); // # of idles that have to be
    
    return tasks.size() + idles;
  }
};