/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    int length = 0;
    struct ListNode* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    int target = length - n;

    if (target == 0) {
        struct ListNode* new_head = head->next;
        free(head);
        return new_head;
    }

    struct ListNode* prev = head;
    for (int i = 0; i < target - 1; i++) {
        prev = prev->next;
    }

    struct ListNode* to_delete = prev->next;
    prev->next = to_delete->next; 
    free(to_delete);              

    return head; 
}