// https://leetcode.com/problems/reward-top-k-students/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
using namespace std;

// n = size of report, student_id
// pos = size of positive_feedback
// neg = size of negative_feedback
// time: O(pos + neg + n * log(n))
// space: O(pos + neg + n)

class Solution {
public:
  vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
    int n = report.size();
    
    unordered_map<int, int> points; // id, pts
    unordered_set<string> pos (positive_feedback.begin(), positive_feedback.end());
    unordered_set<string> neg (negative_feedback.begin(), negative_feedback.end());
    
    for (int i = 0; i < n; i++) {
      int id = student_id[i];
      const string& rp = report[i];
      
      stringstream ss (rp);
      string word;
      while (ss >> word) {
        points[id] += pos.count(word) * 3;
        points[id] -= neg.count(word);
      }
    }
    
    vector<pair<int, int>> pairs; // pts, id
    for (const auto& [ id, pts ] : points) {
      pairs.emplace_back(pts, id);
    }
    
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first == b.first ? a.second < b.second : a.first > b.first;
    });
    
    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.emplace_back(pairs[i].second);
    }
    
    return res;
  }
};