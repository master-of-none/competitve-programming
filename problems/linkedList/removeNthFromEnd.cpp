#include "listNode.h"

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = dummy->next;

    while (n) {
        fast = fast->next;
        n--;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}