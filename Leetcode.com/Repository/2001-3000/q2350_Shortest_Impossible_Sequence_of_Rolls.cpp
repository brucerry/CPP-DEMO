// https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/

#include <vector>
using namespace std;

// time: O(n)
// space: O(k)
class TrackVisited {
public:
  int shortestSequence(vector<int>& rolls, int k) {
    vector<char> visited (k + 1);
    int seq = 1, count = 0;
    for (const int& num : rolls) {
      if (visited[num] == 0) {
        visited[num] = 1;
        if (++count == k) {
          fill(visited.begin(), visited.end(), 0);
          count = 0;
          seq++;
        }
      }
    }
    return seq;
  }
};

// time: O(n)
// space: O(k)
class CountingNum {
public:

  // For a sequence of size 1, all [1, k] numbers must appear in rolls.
  // For a sequence of size 2, all [1, k] numbers must appear after all [1, k] numbers appear in rolls.
  // ... and so on.

  int shortestSequence(vector<int>& rolls, int k) {
    int seq = 0, cnt = 0, counts[100001] = {};
    for (const int& num : rolls) {
      if (counts[num] == seq) {
        counts[num]++;
        if (++cnt % k == 0)
          seq++;
      }
    }
    return seq + 1;
  }
};