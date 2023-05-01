// https://leetcode.com/problems/reverse-linked-list/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(n)
class Recursive {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        
        ListNode* newhead = head;
        if (head->next) {
            newhead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
        }

        return newhead;
    }
};

// time: O(n)
// space: O(1)
class Iterative {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head, *prev = nullptr;
        while (cur) {
            ListNode* tmpnext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmpnext;
        }
        return prev;
    }
};