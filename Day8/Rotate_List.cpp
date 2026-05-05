/*
Given the head of a linked list, rotate the list to the right by k places.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (!head || !head->next || k == 0) return head;
//         for(int i=1;i<=k;i++){
//             ListNode *temp=head;
//             ListNode *prev;
//             while(temp->next!=nullptr){
//                 prev=temp;
//                 temp=temp->next;
//             }
//             prev->next=nullptr;
//             temp->next=head;
//             head=temp;
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n=1;
        ListNode *temp=head;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        temp->next=head;
        ListNode *tail=head;
        for(int i=1;i<n-k;i++){
            tail=tail->next;
        }
        ListNode* newHead=tail->next;
        tail->next=nullptr;

        return newHead;
    }
};