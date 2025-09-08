#include "header.h"
#include "listNode.h"
using namespace std;

ListNode* getkth(ListNode* cur, int k) {
    while (cur and k > 0) {
        cur = cur->next;
        k -= 1;
    }
    return cur;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* groupPrev = dummy;

    while (true) {
        ListNode* kth = getkth(groupPrev, k);
        if (kth == nullptr) break;
        ListNode* groupNext = kth->next;
        ListNode *prev = groupNext, *cur = groupPrev->next;

        while (cur != groupNext) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode* temp = groupPrev->next;
        groupPrev->next = kth;
        groupPrev = temp;
    }
    return dummy->next;
}