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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0 || head->next == NULL){
            return head;
        }

        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp -> next;
        }

        k = k%n;
        if(k == 0){
            return head;
        }

        temp = head;
        while(temp -> next != NULL){
            temp = temp->next;
        }
        temp -> next = head;

        ListNode* tail = head;
        for(int i = 0; i< n-k-1; i++){
            tail = tail -> next;
        }

        ListNode* newHead = tail -> next;
        tail-> next = NULL;
         
        return newHead;

    }
};