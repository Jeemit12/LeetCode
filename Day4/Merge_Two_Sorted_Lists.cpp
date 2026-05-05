/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* j = list1;
        ListNode* k = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;

        while (j != nullptr && k != nullptr) {
            if (j->val <= k->val) {
                result->next = j;
                j = j->next;
            } else {
                result->next = k;
                k = k->next;
            }
            result = result->next;  
        }

        if (j != nullptr) {
            result->next = j;
        } else {
            result->next = k;
        }

        return dummy->next;
    }
};