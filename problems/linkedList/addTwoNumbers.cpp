#include "listNode.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    int carry = 0;
    ListNode *cur = dummy;
    while (l1 or l2 or carry) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int res = v1 + v2 + carry;

        carry = res / 10;
        res = res % 10;
        cur->next = new ListNode(res);

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;

        cur = cur->next;
    }
    return dummy->next;
}