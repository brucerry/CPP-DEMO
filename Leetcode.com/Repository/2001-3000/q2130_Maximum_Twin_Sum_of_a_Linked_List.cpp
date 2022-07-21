// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(1)
class ReverseHalfList {
public:
  int pairSum(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* prev = nullptr, *cur = slow;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    
    int maxSum = 0;
    ListNode* l = head, *r = prev;
    while (r) {
      maxSum = max(maxSum, l->val + r->val);
      l = l->next;
      r = r->next;
    }
    
    return maxSum;
  }
};

// time: O(n)
// space: O(n)
class RecordSums {
public:
  int pairSum(ListNode* head) {
    ListNode* slow = head, *fast = head;
    int halfLen = 0;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      halfLen++;
    }
    
    vector<int> sums (halfLen);
    ListNode* l = head, *r = slow;
    int i = 0, j = halfLen - 1;
    while (r) {
      sums[i] += l->val;
      sums[j] += r->val;
      l = l->next;
      r = r->next;
      i++;
      j--;
    }
    
    return *max_element(sums.begin(), sums.end());
  }
};