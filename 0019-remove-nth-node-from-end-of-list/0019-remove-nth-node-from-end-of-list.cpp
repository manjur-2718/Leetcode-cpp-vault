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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        
        for(int i=0; i<=n; i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next=toDelete->next;
        delete toDelete;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};