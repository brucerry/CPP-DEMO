// https://leetcode.com/problems/online-election/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(n) for constructor, O(log(n)) for q()
// space: O(n)

class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    this->times = times;
    int n = persons.size(), leader = -1;
    unordered_map<int, int> votes; // id, vote
    for (int i = 0; i < n; i++) {
      int id = persons[i], time = times[i];
      leader = ++votes[id] >= votes[leader] ? id : leader;
      timeLeader[time] = leader;
    }
  }
  
  int q(int t) {
    auto it = upper_bound(times.begin(), times.end(), t);
    return timeLeader[*(--it)];
  }

private:
  unordered_map<int, int> timeLeader; // time, leader
  vector<int> times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */