#include "header.h"
#include "listNode.h"
using namespace std;

void reorderList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* cur = slow->next;
    slow->next = NULL;
    ListNode* prev = NULL;

    while (cur != NULL) {
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    ListNode* first = head;
    ListNode* second = prev;

    while (second != NULL) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}