// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    vector<int> targets {tops[0], bottoms[0]};
    const int len = tops.size();

    for (int& target : targets) {
      int missingTop = 0;
      int missingBottom = 0;

      for (int i = 0; i < len; i++) {
        if (tops[i] != target && bottoms[i] != target) break;

        if (tops[i] != target) missingTop++;
        if (bottoms[i] != target) missingBottom++;
        if (i == len - 1) return min(missingTop, missingBottom);
      }
    }

    return -1;
  }
};

// class Solution {
// public:
//   int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//     const int len = tops.size();
//     unordered_map<int, unordered_set<int>> top;
//     unordered_map<int, unordered_set<int>> bottom;

//     for (int i = 0; i < len; i++) {
//       top[tops[i]].insert(i);
//       bottom[bottoms[i]].insert(i);
//     }

//     vector<int> result (6, INT_MAX);

//     for (auto& pair : top) {
//       int value = pair.first;
//       unordered_set<int> indexes = pair.second;

//       if (indexes.size() == len) return 0;

//       if (bottom.count(value)) {
//         int neededCount = len - indexes.size();
//         const int tmp = neededCount;
//         if (neededCount <= bottom[value].size()) {
//           for (const int& idx : bottom[value]) {
//             if (indexes.count(idx) == 0) {
//               neededCount--;
//               if (neededCount == 0) {
//                 result[value - 1] = min(result[value - 1], tmp);
//                 break;
//               }
//             }
//           }
//         }
//       }
//     }

//     for (auto& pair : bottom) {
//       int value = pair.first;
//       unordered_set<int> indexes = pair.second;

//       if (indexes.size() == len) return 0;

//       if (top.count(value)) {
//         int neededCount = len - indexes.size();
//         const int tmp = neededCount;
//         if (neededCount <= top[value].size()) {
//           for (const int& idx : top[value]) {
//             if (indexes.count(idx) == 0) {
//               neededCount--;
//               if (neededCount == 0) {
//                 result[value - 1] = min(result[value - 1], tmp);
//                 break;
//               }
//             }
//           }
//         }
//       }
//     }

//     int ans = *min_element(result.begin(), result.end());
//     return ans == INT_MAX ? -1 : ans;
//   }
// };