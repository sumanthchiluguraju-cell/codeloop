/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {

        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if (l1)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

struct ListNode* mergeRange(struct ListNode** lists, int left, int right) {

    if (left > right)
        return NULL;

    if (left == right)
        return lists[left];

    int mid = left + (right - left) / 2;

    struct ListNode *l1 = mergeRange(lists, left, mid);
    struct ListNode *l2 = mergeRange(lists, mid + 1, right);

    return merge(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0)
        return NULL;

    return mergeRange(lists, 0, listsSize - 1);
}