#include "header.h"
#include "listNode.h"

using namespace std;

ListNode *mergeKList(vector<ListNode *> &lists) {
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
        vector<ListNode *> merged;

        for (int i = 0; i < lists.size(); i += 2) {
            ListNode *l1 = lists[i];
            ListNode *l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
            merged.push_back(mergeSortedList(l1, l2));
        }
        lists = move(merged);
    }
    return lists[0];
}

ListNode *mergeSortedList(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;

    while (l1 and l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) cur->next = l1;
    if (l2) cur->next = l2;

    return dummy->next;
}