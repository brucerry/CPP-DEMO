// https://leetcode.com/problems/random-pick-with-weight/

#include <vector>
#include <random>
#include <numeric>
using namespace std;

// time: O(n) for constructor, O(log(n)) for pickIndex()
// space: O(n)

class Solution {
public:
  Solution(vector<int>& w) {
    prefix = w;
    partial_sum(prefix.begin(), prefix.end(), prefix.begin());
    random_device rd;
    gen = mt19937(rd());
    distrib = uniform_int_distribution<int>(1, prefix.back());
  }
  
  int pickIndex() {
    int val = distrib(gen);
    auto it = lower_bound(prefix.begin(), prefix.end(), val);
    return it - prefix.begin();
  }

private:
  mt19937 gen;
  uniform_int_distribution<int> distrib;
  vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */