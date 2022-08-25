// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// t = size of tasks
// time: O(t)
// space: O(26) => O(1)
class Greedy {
public:
  int leastInterval(vector<char>& tasks, int n) {
    int counts[26] {}, maxCount = -1;
    for (const char& c : tasks)
      maxCount = max(maxCount, ++counts[c - 'A']);
    
    int result = (maxCount - 1) * (n + 1);
    for (const int& count : counts) {
      if (count == maxCount)
        result++;
    }
    
    return max(result, (int)tasks.size());
  }
};

// t = size of tasks
// time: O(t + 26 * log(26)) => O(t)
// space: O(26) => O(1)
class MaxHeap {
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
    
    queue<pair<int, int>> cooldown; // count, ready time
    
    int curTime = 0;
    while (ready.size() or cooldown.size()) {
      if (ready.size()) {
        int count = ready.top();
        ready.pop();
        if (--count)
          cooldown.emplace(count, curTime + n);
      }
      
      while (cooldown.size() and cooldown.front().second <= curTime) {
        ready.emplace(cooldown.front().first);
        cooldown.pop();
      }
      
      if (ready.size() == 0 and cooldown.size())
        curTime = cooldown.front().second;
      else
        curTime++;
    }
    
    return curTime;
  }
};

// t = size of tasks
// time: O(t)
// space: O(26) => O(1)
class Maths {
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