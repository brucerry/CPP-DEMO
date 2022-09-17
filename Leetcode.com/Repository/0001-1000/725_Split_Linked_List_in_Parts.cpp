// https://leetcode.com/problems/split-linked-list-in-parts/

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n + k)
// space: O(1)

class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = numberOfNodes(head);
    int lenOfEachList = n / k, remain = n % k;
    
    vector<ListNode*> result (k);
    for (int i = 0; i < k; i++) {
      ListNode* eachHead = head, *eachTail = nullptr;
      for (int j = 0; j < lenOfEachList and head; j++) {
        eachTail = head;
        head = head->next;
      }
      if (remain and head) {
        remain--;
        eachTail = head;
        head = head->next;
      }
      if (eachTail)
        eachTail->next = nullptr;
      result[i] = eachHead;
    }
    
    return result;
  }
  
private:
  int numberOfNodes(ListNode* node) {
    int n = 0;
    for (; node; node = node->next, n++);
    return n;
  }
};