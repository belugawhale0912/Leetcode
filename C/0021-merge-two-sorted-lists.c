/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to act as the start of the merged list
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *cursor = &dummy;

    // Traverse both lists and attach the smaller value node
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            cursor->next = list1;
            list1 = list1->next;
        } else {
            cursor->next = list2;
            list2 = list2->next;
        }
        cursor = cursor->next;
    }

    // Attach whatever is left from either list
    if (list1 != NULL) {
        cursor->next = list1;
    } else {
        cursor->next = list2;
    }

    // dummy.next points to the actual head of the merged list (which is on the heap)
    return dummy.next;
}
