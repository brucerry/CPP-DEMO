// https://leetcode.com/problems/spiral-matrix-iv/

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    
    vector<vector<int>> result (m, vector<int>(n));
    while (left <= right and top <= bottom) {
      for (int c = left; c <= right; c++) {
        result[top][c] = head ? head->val : -1;
        if (head)
          head = head->next;
      }
      top++;
      
      for (int r = top; r <= bottom; r++) {
        result[r][right] = head ? head->val : -1;
        if (head)
          head = head->next;
      }
      right--;
      
      if (left > right or top > bottom)
        break;
      
      for (int c = right; c >= left; c--) {
        result[bottom][c] = head ? head->val : -1;
        if (head)
          head = head->next;
      }
      bottom--;
      
      for (int r = bottom; r >= top; r--) {
        result[r][left] = head ? head->val : -1;
        if (head)
          head = head->next;
      }
      left++;
    }
    
    return result;
  }
};