/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode tempNode;
    tempNode.next = NULL;
    struct ListNode* current = &tempNode;
    
    int carry = 0;
    struct ListNode* p = l1;
    struct ListNode* q = l2;

    // Continue as long as there are digits left in l1, l2, or a leftover carry
    while (p != NULL || q != NULL || carry != 0) {
        int x = (p != NULL) ? p->val : 0;
        int y = (q != NULL) ? q->val : 0;
        
        int sum = carry + x + y;
        carry = sum / 10; // Compute new carry (0 or 1)
        
        // Allocate and populate the new node
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL; // Always terminate the tail!
        
        // Advance pointers if possible
        if (p != NULL) p = p->next;
        if (q != NULL) q = q->next;
    }

    struct ListNode* result = tempNode.next;
    return result;
}